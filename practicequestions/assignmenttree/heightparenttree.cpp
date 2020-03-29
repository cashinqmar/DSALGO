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
int height(TreeNode * root){
    if(root==NULL)return 0;
    else return max(height(root->left),height(root->right))+1;
}


int main(){
    int n;
    cin>>n;
    vector<TreeNode*> nodes(n);
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
        nodes[i]=new TreeNode(i);
    }
    // TreeNode* root=createlevel(arr);
    TreeNode * root=NULL;
    for(int i=0;i<n;i++){
        if(arr[i]!=-1){
        if(!nodes[arr[i]]->left)nodes[arr[i]]->left=nodes[i];
        else nodes[arr[i]]->right=nodes[i];
        }
        else root=nodes[i];
    }

    cout<<height(root)-1;

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