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


TreeNode* head=NULL;

TreeNode* DLL(TreeNode * node,bool isleft,TreeNode *parent){
    if(node==NULL)return NULL;
static TreeNode* prev = NULL; 

    if(!node->left&&!node->right){
    if(prev==NULL){
    //   TreeNode * nnode=new TreeNode(node->val);
      head=node;
      prev=node;
    }
    else{
        // TreeNode * nnode=new TreeNode(node->val);
        prev->right=node;
        node->left=prev;
        prev=node;
    }
   return NULL;
    // if(isleft)parent->left=NULL;
    // else parent->right=NULL;
}
   node->left= DLL(node->left,true,node);
   node->right= DLL(node->right,false,node);

}

TreeNode* solve(TreeNode* root){
if(!root->left&&!root->right){
    head=root;
}
 TreeNode*ans=   DLL(root,true,root);
 TreeNode* temp=(head);
TreeNode* tail=NULL;

 while(temp){
     cout<<temp->val<<" ->";
     tail=temp;
     temp=temp->right;
 }
cout<<" ."<<endl;
temp=tail;
while(temp){
     cout<<temp->val<<" ->";
     tail=temp;
     temp=temp->left;
 }
 cout<<" ."<<endl;
return ans;
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
    TreeNode* root=createlevel(arr);
    // display(root);
    root=solve(root);
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
    cout<<s<<endl;
    display(root->left);
    display(root->right);
}