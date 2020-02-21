#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    TreeNode* next=NULL;
    int val;
    TreeNode(int val){
        left=NULL;
        right=NULL;
        this->val=val;
    }
};
void display(TreeNode*);
TreeNode* createlevel(vector<int>&);


bool helper(TreeNode *l,TreeNode *r){
     if(l==NULL&&r==NULL)return true;
        if(l==NULL||r==NULL)return false;
        // if(l->val!=r->val)return false;
        return helper(l->left,r->right)&&helper(l->right,r->left);
}
void solve(TreeNode * root){
    bool res;
if(!root)
    res= true;

    // mirror(root->left);
  else res= helper(root->left,root->right);
    // mirror(root->left);

if(res)cout<<"true";
else cout<<"false";
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
    display(root);
    // solve(root);
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
    cout<<s<<endl;
    display(root->left);
    display(root->right);
}
