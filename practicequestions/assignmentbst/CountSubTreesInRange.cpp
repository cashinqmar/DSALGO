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
//count of nodes whose subtrees fall in the range of lb and ub
// class range{
//     public:
//     int lb;
//     int rb;
// };

// range helper(TreeNode* root ,int minm,int maxm,int &count){
//     if(root->left==NULL&&root->right==NULL){
//         range temp;
//         temp.lb=root->val;
//         temp.rb=root->val;
//         if(minm<=temp.lb&&temp.rb<=maxm)count++;
//         return temp;
//     }

//     else if(root->left==NULL){
//         range r=helper(root->right,minm,maxm,count);
//         range temp;
//         temp.lb=root->val;
//         temp.rb=r.rb;
//         if(minm<=temp.lb&&temp.rb<=maxm)count++;
//         return temp;
//     }
//     else if(root->right==NULL){
//          range l=helper(root->left,minm,maxm,count);
//         range temp;
//         temp.lb=l.lb;
//         temp.rb=root->val;
//         if(minm<=temp.lb&&temp.rb<=maxm)count++;
//         return temp;

//     }
//     else{
//          range l=helper(root->left,minm,maxm,count);
//          range r=helper(root->right,minm,maxm,count);
//         range temp;
//         temp.lb=l.lb;
//         temp.rb=r.rb;
//         if(minm<=temp.lb&&temp.rb<=maxm)count++;
//         return temp;
//     }

// }
bool range(TreeNode * root,int lb,int ub,int &count){
    if(!root)return true;
    bool l=range(root->left,lb,ub,count);
    bool r=range(root->right,lb,ub,count);
    
    if(l&&r&&(lb<=root->val&&root->val<=ub)){count++;return true;}
     return false;
}
void solve(TreeNode *root,int lb,int ub){
    int count=0;
    range(root,lb,ub,count);
     cout<<count;
}

int main(){
    int n,lb,ub;
    cin>>lb>>ub>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    TreeNode* root=createlevel(arr);
    // display(root);
    solve(root,lb,ub);

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