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









void leftprint(TreeNode* root){
  if(root==NULL)return ;
  if(root->left==NULL&&root->right==NULL)return;
  cout<<root->val<<" ";
  leftprint(root->left);
}


TreeNode* head=NULL;


void DLL(TreeNode * node,TreeNode *&end){
    if(node==NULL)return;
static TreeNode* prev = NULL; 

    DLL(node->left,end);
    if(prev==NULL){
     head=node;
    }
    else{
        prev->right=node;
        node->left=prev;
    }
    prev=node;
    end=node;
    DLL(node->right,end);

}

void solve(TreeNode* root){
    TreeNode *end=NULL;
 DLL(root,end);

 TreeNode* temp=(head);
TreeNode* tail=end;

tail->right=head;
head->left=tail;
int count=20;
 while(count--){
     cout<<temp->val<<" ->";
     tail=temp;
     temp=temp->right;
 }
cout<<" ."<<endl;
temp=tail;
// while(temp){
//      cout<<temp->val<<" ->";
//      tail=temp;
//      temp=temp->left;
//  }
 cout<<" .";

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
    solve(root);

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