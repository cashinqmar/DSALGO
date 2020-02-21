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

class element{
    public:
    TreeNode *node=NULL;
    bool l=false;
    bool sd=false;
    bool r=false;
    element(TreeNode* node){
        this->node=node;
    }
};

// void inorderstack(TreeNode * root){
//     stack<element*> s;
//     element* a=new element(root);
//     s.push(a);

//     while(!s.empty()){
//         element* top=s.top();
//         if(!top->l){
//             if(top->node->left){
//                 s.push(new element(top->node->left));
//             }
//             top->l=true;
//         }
//         else  if(!top->sd){
//                 cout<<top->node->val<<" ";
//                 top->sd=true;
//             }

//         else if(!top->r){
//             if(top->node->right){
//                 s.push(new element(top->node->right));
//             }
//             top->r=true;
//         }
//         else s.pop();
//     }
// }


void getVerticalOrder(TreeNode* root, int hd, map<int, vector<int>> &m) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Store current node in map 'm' 
    m[hd].push_back(root->val); 
  
    // Store nodes in left subtree 
    getVerticalOrder(root->left, hd-1, m); 
  
    // Store nodes in right subtree 
    getVerticalOrder(root->right, hd+1, m); 
} 

void printVerticalOrder(TreeNode* root) 
{ 
    // Create a map and store vertical order in map using 
    // function getVerticalOrder() 
    map < int,vector<int> > m; 
    int hd = 0; 
    getVerticalOrder(root, hd,m); 
  
    // Traverse the map and print nodes at every horigontal 
    // distance (hd) 
    map< int,vector<int> > :: iterator it; 
    for (it=m.begin(); it!=m.end(); it++) 
    { 
        for (int i=0; i<it->second.size(); ++i) 
            cout << it->second[i] << " "; 
        cout << endl; 
    } 
} 



// void solve(TreeNode* root){
//     if(!root)cout<<"";
//     queue<pair<TreeNode*,int>> q;
//     q.push(make_pair(root,0));
//     map<int,vector<int>> m;
//     int hd;
//     while(!q.empty()){
//         int s=q.size();
//         while(s--){
//             pair<TreeNode*,int> temp=q.front();
//             q.pop();
//             hd=temp.second;
//             TreeNode* yo=temp.first;
//             m[hd].push_back(yo->val);

//             if(yo->left){
//                 q.push(make_pair(yo->left,hd-1));
//             }
//             if(yo->right){
//                 q.push(make_pair(yo->right,hd+1));
//             }
//         }
//         if(q.size()==0)break;
//     }

//     for(auto i:m){
//         for(int e:i.second)cout<<e<<" ";
//         cout<<endl;
//     }
// }





















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
    // solve(root);
    printVerticalOrder(root);

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