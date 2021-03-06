#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    int val;
    TreeNode(int val){
        left=NULL;
        right=NULL;
        next=NULL;
        this->val=val;
    }
};
void display(TreeNode*);
TreeNode* createlevel(vector<int>&);

void helper(TreeNode * root,int x){
    if(root==NULL)return ;
    if(root->val==x){
        if(root->next)cout<<root->next->val<<endl;
        else cout<<"Not Found"<<endl;
    }
    helper(root->left,x);
    helper(root->right,x);
}

void solve(TreeNode * root,int x){
if(root==NULL){
    return ;
}
queue<TreeNode*> q;
q.push(root);

while(!q.empty()){
TreeNode *prev=NULL;
int s=q.size();

while(s--){
TreeNode *temp=q.front();
q.pop();
if(prev){
    prev->next=temp;
}
 prev=temp;

if(temp->left)q.push(temp->left);
if(temp->right)q.push(temp->right);
}

}

helper(root,x);

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

    int x;
    cin>>x;
    TreeNode* root=createlevel(arr);
    // display(root);
    solve(root,x);
    // display(root);

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
    s+="["+ (root->next!=NULL?to_string(root->next->val):"null")+"]";
    cout<<s<<endl;
    display(root->left);
    display(root->right);
}