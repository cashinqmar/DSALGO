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

// BST nahi banana
bool helper(vector<int>& arr1,vector<int>& arr2,int minm,int maxm,int idx1,int idx2){
    int i,j;
    int n=arr1.size();
    for(i=idx1;i<n;i++)if(arr1[i]>minm&&arr1[i]<maxm)break;
    for(j=idx2;j<n;j++)if(arr2[j]>minm&&arr2[j]<maxm)break;

    if(i==n&&j==n)return true;
    if(i==n||j==n)return false;

    if(arr1[i]==arr2[j]){
        return helper(arr1,arr2,minm,arr1[i],i+1,j+1)&&helper(arr1,arr2,arr1[i],maxm,i+1,j+1);
    }
    return false;
}
void solve(vector<int>& arr1,vector<int>& arr2){
if(helper(arr1,arr2,INT_MIN,INT_MAX,0,0))cout<<"true";
else cout<<"false";
}

int main(){
    int n;
    cin>>n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr1[i]=x;
    }
     for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr2[i]=x;
    }
    // TreeNode* root=createlevel(arr);
    // display(root);
    solve(arr1,arr2);

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