#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    TreeNode*random;
    int val;
    TreeNode(int val){
        left=NULL;
        right=NULL;
        this->val=val;
    }
};
void display(TreeNode*);
TreeNode* createlevel(vector<int>&);
void preorder(TreeNode *root,map<int,TreeNode*> &m){
    if(!root)return;
    m[root->val]=root;
    preorder(root->left,m);
    preorder(root->right,m);
}

void preorder1(TreeNode *root,map<int,TreeNode*> &m,map<int,int>& act){
    if(!root)return;
    root->random=m[act[root->val]];
    
    preorder1(root->left,m,act);
    preorder1(root->right,m,act);
}
void solve(TreeNode * root,map<int,int> &act){
    map<int,TreeNode*>m;
    preorder(root,m);
    preorder1(root,m,act);
    display(root);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int k=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
        k=max(k,x);
    }


    TreeNode* root=createlevel(arr);
    // display(root);
    map<int,int> m;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        m[x]=y;
    }
    solve(root,m);
    // display(root);

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
    s+=" => "+to_string(root->val)+"[R:"+to_string(root->random->val)+"]"+" <= ";
    s+=root->right?to_string(root->right->val):".";

    cout<<s<<endl;
    display(root->left);
    display(root->right);
}