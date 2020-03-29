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


TreeNode* lca(TreeNode* root, int p, int q){
        if(root==NULL)return NULL;
       
        if(root->val<p){
            return lca(root->right,p,q);
        }
        else if(root->val>q){
             return lca(root->left,p,q);
        }
        else return root;
    }

void helper(TreeNode *root,int data,int & maxm){
    if(root==NULL)return;
maxm=max(root->val,maxm);
    if(root->val==data)return;
    

    
    if(root->val>data)helper(root->left,data,maxm);
    else helper(root->right,data,maxm);
}
void solve(TreeNode * root,int l,int r){
    if(l>r)swap(l,r);
    TreeNode * ancestor=lca(root,l,r);

    int maxm=INT_MIN;
    helper(ancestor,l,maxm);
    helper(ancestor,r,maxm);
    cout<<maxm;
}

int main(){
    int n,l,r;
    cin>>l>>r>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    TreeNode* root=createlevel(arr);
    // display(root);
    solve(root,l,r);

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
    s+=" => "+to_string(root->val)+" <= ";
    s+=root->right?to_string(root->right->val):".";

    cout<<s<<endl;
    display(root->left);
    display(root->right);
}