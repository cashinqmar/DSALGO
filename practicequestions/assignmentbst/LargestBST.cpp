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


 int bstsize=0;
 TreeNode* bstroot=NULL;

class baby{
    public:
    bool isbst;
    int size;
    int minm;
    int maxm;
};
baby helper(TreeNode *root){
    if(root==NULL){
      baby temp;
       temp.isbst=true;
       temp.size=0;
       temp.minm=INT_MAX;
       temp.maxm=INT_MIN;
       return temp;
    }

   baby l=helper(root->left);
   baby r=helper(root->right);

   if(l.isbst&&r.isbst){
       int lval=root->left?root->left->val:INT_MIN;
       int rval=root->right?root->right->val:INT_MAX;

       if(root->val>lval&&root->val<rval&&l.maxm<root->val&&root->val<r.minm){
         baby temp;
       temp.isbst=true;
       temp.size=l.size+r.size+1;
       temp.minm=min(l.minm,root->val);
       temp.maxm=max(r.maxm,root->val);

       if(bstsize<temp.size){
           bstsize=temp.size;
           bstroot=root;
       }
       return temp;

       }
   }

       
         baby temp;
       temp.isbst=false;
       temp.size=0;
       temp.minm=root->val;
       temp.maxm=root->val;
       return temp;
   }
void solve(TreeNode *root){
    helper(root);
    cout<<bstroot->val<<" "<<bstsize;
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
    s+=" => "+to_string(root->val)+" <= ";
    s+=root->right?to_string(root->right->val):".";

    cout<<s<<endl;
    display(root->left);
    display(root->right);
}