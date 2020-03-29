#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
     char val;
    TreeNode(char val){
        left=NULL;
        right=NULL;
        this->val=val;
    }
};
void display(TreeNode*);
TreeNode* createlevel(vector<int>&);

void solve(string &s){
    stack<TreeNode*> st;
    TreeNode * root=NULL;
    for(int i=0;i<s.size();i++){
       TreeNode *temp=new TreeNode((char)s[i]);
       if(s[i]=='*'||s[i]=='-'||s[i]=='+'||s[i]=='/'){

           TreeNode* t1=st.top();
           st.pop();
           TreeNode* t2=st.top();
           st.pop();
           temp->right=t1;
           temp->left=t2;
           st.push(temp);
       }
       else{
           st.push(temp);
       }
       if(i==s.size()-1)root=temp;
    }
    display(root);
}

int main(){
    string n;
    cin>>n;
    // vector<int> arr(n);
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     arr[i]=x;
    // }
    // TreeNode* root=createlevel(arr);
    // display(root);
    solve(n);

}

// TreeNode* createlevel(vector<int> &arr){
//     int n=arr.size();
//     vector<TreeNode*> root(n);
//     for(int i=0;i<n;i++){
//         if(arr[i]!=-1){
//           root[i]=new TreeNode(arr[i]);
//             if(i>0){
//                 int pi=(i-1)/2;
//                 if(2*pi+1==i){
//                     root[pi]->left=root[i];
//                 }
//                 else{
//                     root[pi]->right=root[i];
//                 }
//             }
//         }
//     }
//     return root[0];
// }
void display(TreeNode* root){
   if(root==NULL)return;


    root->left?cout<<char(root->left->val):cout<<".";
    cout<<" => "<<char(root->val)<<" <= ";
   root->right?cout<<char(root->right->val):cout<<".";

    cout<<endl;
    display(root->left);
    display(root->right);
}