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

void morris(TreeNode *root){
    TreeNode* curr=root;

int count=0;
    while(curr){
        if(curr->left==NULL){
            count++;
            curr=curr->right;
        }
        else{
            TreeNode *predecessor=curr->left;
            while(predecessor->right!=NULL&&predecessor->right!=curr){
                predecessor=predecessor->right;
            }
          
          if(predecessor->right==NULL){
              predecessor->right=curr;
              curr=curr->left;
          }
          else{
              predecessor->right=NULL;
              count++;
              curr=curr->right;
          }
        }
    }

    if(count%2==1){
        count=(count+1)/2;
         TreeNode* curr=root;

          while(curr){
        if(curr->left==NULL){
            count--;
          
            if(count==0){
                cout<<curr->val;
            }
            curr=curr->right;
        }
        else{
            TreeNode *predecessor=curr->left;
            while(predecessor->right!=NULL&&predecessor->right!=curr){
                predecessor=predecessor->right;
            }
          
          if(predecessor->right==NULL){
              predecessor->right=curr;
              curr=curr->left;
          }
          else{
              predecessor->right=NULL;
             count--;
    
            if(count==0){
                cout<<curr->val;
            }
              curr=curr->right;
          }
        }
    }
    }

    else{ 
          TreeNode*  curr=root;

        int a=count/2;
        int b=a+1;
        int first=-1;
        int second=-1;
        count=0;
          while(curr){
        if(curr->left==NULL){
            count++;
          
            if(count==a){
              first=curr->val;
            }
            if(count==b){
                second==curr->val;
            }
            curr=curr->right;
        }
        else{
            TreeNode *predecessor=curr->left;
            while(predecessor->right!=NULL&&predecessor->right!=curr){
                predecessor=predecessor->right;
            }
          
          if(predecessor->right==NULL){
              predecessor->right=curr;
              curr=curr->left;
          }
          else{
              predecessor->right=NULL;
              count++ ;
              
               if(count==a){
              first=curr->val;
            }
            if(count==b){
                second=curr->val;
            }
              curr=curr->right;
          }
        }
    }
   cout<<(float)(first+second)/2;
      

    }
}

void solve(TreeNode *root){
    morris(root);
    
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
    s+=" => "+to_string(root->val)+" <= ";
    s+=root->right?to_string(root->right->val):".";

    cout<<s<<endl;
    display(root->left);
    display(root->right);
}