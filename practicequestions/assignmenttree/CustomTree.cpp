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

void solve(string s1,string s2){
int l=s1.size();
map<char,TreeNode*> m;

map<char,int> vis;

for(int i=0;i<l;i++){
    if(m.find(s1[i])==m.end())
    m[s1[i]]=new TreeNode(s1[i]);

    if(m.find(s2[i])==m.end())
    m[s2[i]]=new TreeNode(s2[i]);

    if(m[s1[i]]->left==NULL){
        m[s1[i]]->left=m[s2[i]];
    }
    else{
       m[s1[i]]->right= m[s2[i]];
    }


    vis[s1[i]]++;
}


for(int i=0;i<l;i++){
    vis[s2[i]]=0;
}


vector<char> roots;
for(auto e:vis){
    if(e.second>0)
    roots.push_back(e.first);
}

for(auto e:roots){
display(m[e]);
cout<<endl;
}

}



















int main(){
    // int n;
    // cin>>n;
    // vector<int> arr(n);
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     arr[i]=x;
    // }
    // TreeNode* root=createlevel(arr);
    // display(root);
    string s1,s2;
    cin>>s1>>s2;
    solve(s1,s2);

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


    if(root->left)
    cout<<(root->left->val);
    else cout<<".";
    cout<<" <= ";
    cout<<(root->val);
    cout<<" => ";
    if(root->right)
    cout<<(root->right->val);
    else cout<<".";
    cout<<endl;
    display(root->left);
    display(root->right);
}