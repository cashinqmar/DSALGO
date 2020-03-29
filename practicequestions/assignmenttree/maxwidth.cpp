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

int maxwidthlevel(TreeNode *root){
queue<TreeNode*> q;
q.push(root);
int ans=1;
while(!q.empty()){
    int t=q.size();
    ans=max(ans,t);
    while(t--){
      TreeNode * temp=q.front();
      q.pop();

      if(temp->left)q.push(temp->left);
      if(temp->right)q.push(temp->right);
    }
}

return ans;
}

int height(TreeNode * root){
    if(root==NULL)return 0;
    else return max(height(root->left),height(root->right))+1;
}

void preorder(TreeNode *root,int level,vector<int> &count){
    if(root){
        count[level]++;
        preorder(root->left,level+1,count);
        preorder(root->right,level+1,count);
    }
    
}
int maxwidthpreorder(TreeNode *root){
int h=height(root);
vector<int> count(h+1,0);
preorder(root,0,count);
int ans=0;
for(auto i:count)ans=max(ans,i);
return ans;
}


void solve(TreeNode* root){
    int width1=maxwidthlevel(root);
    int width2=maxwidthpreorder(root);
    cout<<width1<<" "<<width2;

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