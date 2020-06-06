#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
class TreeNode {
    public:
    TreeNode* left=NULL;
    TreeNode* right=NULL;
    int val;
    TreeNode(int val){
        this->val=val;
    }
};

void helper(TreeNode *root1,TreeNode* root2,long long int &ans){
    if(root1==NULL||root2==NULL)return ;
    ans=(ans%mod+(root1->val*root2->val)%mod)%mod;
    helper(root1->right,root2->left,ans);
    helper(root1->left,root2->right,ans);
}
long long int image(TreeNode*root){
    if(!root)return 0;
    long long int ans=(root->val)*(root->val);
    helper(root->left,root->right,ans);
    return ans;
}
int main(){
    int t;
    cin>>t;
while(t--){
    int n;
    cin>>n;
    unordered_map<int,TreeNode*> m;
        int par;
        int child;
        char dir;
        TreeNode *root=NULL;
        bool first=false;
    for(int i=0;i<n;i++){
        cin>>par;
        cin>>child;
        cin>>dir;
        if(m.find(par)==m.end()){
            m[par]=new TreeNode(par);
        }
        if(first==false){
            root=m[par];
            first=true;
        }
         if(m.find(child)==m.end()){
            m[child]=new TreeNode(child);
        }
        if(dir=='L'){
            m[par]->left=m[child];
        }
        if(dir=='R'){
             m[par]->right=m[child];
        }
    }

    cout<<image(root)<<"\n";
}
}