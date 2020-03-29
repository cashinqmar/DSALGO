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

TreeNode * bstinorder(vector<int> & arr,int start,int end){
    if(start<=end){
    int m=(end+start)/2;
    
    TreeNode * temp=new TreeNode(arr[m]);
    temp->left=bstinorder(arr,start,m-1);
    temp->right=bstinorder(arr,m+1,end);
    return temp;
    }
    else return nullptr;
}
  
   TreeNode* BSTFromPreOder(vector<int>&arr, int lb, int ele, int ub,int &idx) {

       if(idx>=arr.size()||ele>ub||ele<lb)return nullptr;
       TreeNode * node=new TreeNode(arr[idx]);
       idx++;
       if(idx<arr.size()){
           node->left=BSTFromPreOder(arr,lb,arr[idx],node->val,idx);
       }
       if(idx<arr.size()){
           node->right=BSTFromPreOder(arr,node->val,arr[idx],ub,idx);
       }
       return node;
    }
void solve(vector<int>& arr){
    // sort(arr.begin(),arr.end());
    // TreeNode * root=bstinorder(arr,0,arr.size()-1);
    int idx=0;
    TreeNode* root=BSTFromPreOder(arr,INT_MIN,arr[0],INT_MAX,idx);  

    display(root);
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
    // TreeNode* root=createlevel(arr);
    solve(arr);

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