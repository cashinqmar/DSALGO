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









void leftprint(TreeNode* root){
  if(root==NULL)return ;
  if(root->left==NULL&&root->right==NULL)return;
  cout<<root->val<<" ";
  leftprint(root->left);
}

void printleaf(TreeNode* root){
    if(root==NULL)return;
    if(root->left==NULL&&root->right==NULL)cout<<root->val<<" ";
    printleaf(root->left);
    printleaf(root->right);
}

void rightprint(TreeNode *root){
    if(root==NULL)return;
    if(root->left==NULL&&root->right==NULL)return ;
    rightprint(root->right);
    cout<<root->val<<" ";
}

 void leftprint(TreeNode* root,vector<int>& v){
  if(root==NULL)return ;
  if(root->left==NULL&&root->right==NULL)return;
  if(root->left){
        v.push_back(root->val);
  leftprint(root->left,v);
  }
  else if(root->right){
  v.push_back(root->val);
  leftprint(root->right,v);
  }
}

void printleaf(TreeNode* root,vector<int>& v){
    if(root==NULL)return;
    if(root->left==NULL&&root->right==NULL) v.push_back(root->val);
    printleaf(root->left,v);
    printleaf(root->right,v);
}

void rightprint(TreeNode* root,vector<int>& v){
    if(root==NULL)return;
    if(root->left==NULL&&root->right==NULL)return ;
    if(root->right){
         rightprint(root->right,v);
     v.push_back(root->val);
    }
    else if(root->left){
       rightprint(root->left,v);
     v.push_back(root->val);  
    }
}

    vector<int> boundaryOfBinaryTree(TreeNode * root) {
        // write your code here
        vector<int> v;
        if(!root)return v;
       v.push_back(root->val);
   leftprint(root->left,v);
   printleaf(root->left,v);
   printleaf(root->right,v);
   rightprint(root->right,v);
   return v;
        
    }

void solve(TreeNode* root){
   vector<int> ans= boundaryOfBinaryTree(root);
   for(auto i:ans)cout<<i<<" ";
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
    TreeNode* root=createlevel(arr);
    display(root);
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
    s+="->"+to_string(root->val)+"<-";
    s+=root->right?to_string(root->right->val):".";
    cout<<s<<endl;
    display(root->left);
    display(root->right);
}