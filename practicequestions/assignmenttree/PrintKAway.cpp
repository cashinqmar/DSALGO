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

void kaway(TreeNode* root,int k){
    if(root==NULL)return;
    if(k==0){
        cout<<root->val<<" ";
        return;
    }
    kaway(root->left,k-1);
    kaway(root->right,k-1);
}

int kfar(TreeNode* root, int tar,int k){
    if(root==NULL)return -1;
    if(root->val==tar){
        kaway(root,k);
        return 0;
    }
    int ld=kfar(root->left,tar,k);
    if(ld!=-1){
        if(ld+1==k)cout<<root->val<<" ";
       else kaway(root->right,k-ld-2);
        return ld+1;
    }
    int rd=kfar(root->right,tar,k);
    if(rd!=-1){
        if(rd+1==k)
            cout<<root->val<<" ";
        else kaway(root->left,k-rd-2);
        return rd+1;    
    }
    return -1;
}




















int main(){
    int tar,k;
    cin>>k>>tar;
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
    kfar(root,tar,k);

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