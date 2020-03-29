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
void insert(TreeNode *&root,int data,int &succ){
    if(root==NULL){
        root=new TreeNode(data);
    }

    else if(root->val>data){
        succ=root->val;
        insert(root->left,data,succ);
    }
    else{
        insert(root->right,data,succ);
    }
}
void solve(vector<int> &arr){
 TreeNode*  root=NULL;
    for(int i=arr.size()-1;i>=0;i--){
        int succ=-1;
        insert(root,arr[i],succ);
        arr[i]=succ;
    }
    for(auto i:arr)cout<<i<<" ";
    cout<<"."<<endl;
    
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
    // display(root);
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
    s+=" => "+to_string(root->val)+" <= ";
    s+=root->right?to_string(root->right->val):".";

    cout<<s<<endl;
    display(root->left);
    display(root->right);
}