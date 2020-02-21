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

void solve(TreeNode * root,string ans,int sum,int tar){
    if(root==NULL)return;
    if(root->left==NULL&&root->right==NULL&&sum+root->val==tar){
        cout<<ans<<root->val<<endl;
    }
    solve(root->left,ans+to_string(root->val)+" ",sum+root->val,tar);
    solve(root->right,ans+to_string(root->val)+" ",sum+root->val,tar);

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
    // display(root)
    solve(root,"",0,x);

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