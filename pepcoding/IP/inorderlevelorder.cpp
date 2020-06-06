// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}

Node* helper(vector<int> &inorder,vector<int> & levelorder){
if(inorder.size()==0)return NULL;
Node* root=new Node(levelorder[0]);
int number=levelorder[0];
int count=0;
while(inorder[count]!=number)count++;

vector<int> leftinorder(count);
vector<int> rightinorder(count);
vector<int> leftlevelorder;
vector<int> rightlevelorder;

unordered_map<int,int> mleft,mright;
for(int i=0;i<count;i++){

leftinorder[i]=inorder[i];
mleft[leftinorder[i]]++;
rightinorder[i]=inorder[count+1+i];
mright[rightinorder[i]]++;
}

for(int i=1;i<levelorder.size();i++){
if(mleft[levelorder[i]]>0){
    leftlevelorder.push_back(levelorder[i]);
}
else if(mright[levelorder[i]]>0){
    rightlevelorder.push_back(levelorder[i]);
}
}

root->left=helper(leftinorder,leftlevelorder);
root->right=helper(rightinorder,rightlevelorder);

return root;
}
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
//add code here.
vector<int> in(n);
vector<int> level(n);
for(int i=0;i<n;i++){
    in[i]=inorder[i];
    level[i]=levelOrder[i];
}
return helper(in,level);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
