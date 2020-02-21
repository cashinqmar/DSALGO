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
string act1="";
string act2="";
void helper(TreeNode * root, string ans,int x,int y){
    if(root==NULL)return;
    if(root->val==x){
        act1=ans;
    }
    if(root->val==y){
        act2=ans;
    }
    helper(root->left,ans+to_string(root->val),x,y);
    helper(root->right,ans+to_string(root->val),x,y);
}


void solve(TreeNode* root,int x,int y){
helper(root,"",x,y);
int a=act1.size();
int b=act2.size();

string res="";
for(int i=0;i<min(a,b);i++){
if(act1[i]==act2[i])res+=act1[i];
else break;
}
for(int i=res.size()-1;i>=0;i--)
cout<<res[i]<<" ";

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
    solve(root,x,y);

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