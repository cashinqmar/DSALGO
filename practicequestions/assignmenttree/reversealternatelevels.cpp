#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int val){
        left=NULL;
        right=NULL;
        this->val=val;
    }
};
void display(TreeNode*);
TreeNode* createlevel(vector<int>&);

void preorder( TreeNode *root1,  TreeNode* root2, int lvl) 
{ 
   
    if (root1 == NULL || root2==NULL) 
        return; 

    if (lvl%2 == 0) 
        swap(root1->val, root2->val); 
    preorder(root1->left, root2->right, lvl+1); 
    preorder(root1->right, root2->left, lvl+1); 
} 

void inorder(TreeNode *root,vector<int>& arr,int level){
    if(root==NULL)return;

    inorder(root->left,arr,level+1);
    if(level%2==0){
        arr.push_back(root->val);
    }
    inorder(root->right,arr,level+1);
}
void inorder1(TreeNode *root,vector<int>& arr,int level){
    if(root==NULL)return;
   static int idx=0;
    inorder1(root->left,arr,level+1);
    if(level%2==0){
        root->val=arr[idx++];
    }
    inorder1(root->right,arr,level+1);
}
void solve(TreeNode* root){
vector<int> arr;
inorder(root,arr,1);
reverse(arr.begin(),arr.end());
// preorder(root->left,root->right,0);
inorder1(root,arr,1);
display(root);
}



















int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }

    int x,y;
    cin>>x>>y;
    TreeNode* root=createlevel(arr);
    // display(root);
    solve(root);

}

TreeNode* createlevel(vector<int> &arr){
    int n=arr.size();
    vector<TreeNode*> root(n);
    for(int i=0;i<n;i++){
        if(arr[i]!=-1){
          root[i]=new TreeNode(arr[i]);
            if(i>0){
                int pi=(i-1)/2;
                if(2*pi+1==i){
                    root[pi]->left=root[i];
                }
                else{
                    root[pi]->right=root[i];
                }
            }
        }
    }
    return root[0];
}
void display(TreeNode* root){
  if(root==NULL)return;

    string s;
    s+=root->left?to_string(root->left->val):".";
    s+=" <= "+to_string(root->val)+" => ";
    s+=root->right?to_string(root->right->val):".";
    cout<<s<<endl;
    display(root->left);
    display(root->right);
}