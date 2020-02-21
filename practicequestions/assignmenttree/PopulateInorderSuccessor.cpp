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


TreeNode * prev=NULL;
void solve(TreeNode * root){
if(root==NULL){
    return ;
}

static TreeNode * prev=NULL;
solve(root->left);
if(prev!=NULL){
prev->next=root;
}
prev=root;
solve(root->right);
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
    solve(root);
    display(root);

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