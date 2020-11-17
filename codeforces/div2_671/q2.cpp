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


int main(){
int x,y;
cin>>x>>y;

unordered_map<int,TreeNode*> m1;
unordered_map<int,TreeNode*> m2;

for(int i=0;i<x;i++){
    int a,b;
    char c;
    cin>>a>>b;
    cin>>c;

    if(m1[a]==NULL){
        m1[a]=new TreeNode(a);
    }
    if(m1[b]==NULL){
        m1[b]=new TreeNode(b);
    }

    if(c=='L'){
        m1[a]->left=m1[b];
    }
    else{
         m1[a]->right=m1[b];
    }
}



}