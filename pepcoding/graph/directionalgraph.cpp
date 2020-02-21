#include<bits/stdc++.h>
using namespace std;
int n=6;
vector<vector<int>> graph(n,vector<int>());

void addedge(int u,int v){
    graph[u].push_back(v);
}

void display(){
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto e:graph[i]){
            cout<<e<<" ";
        }
        cout<<endl;
    }
}

void creategraph(){
    addedge(5, 2); 
    addedge(5, 0); 
    addedge(4, 0); 
    addedge(4, 1); 
    addedge(2, 3); 
    addedge(3, 1); 
}

void topological(vector<vector<int>> &graph,int sr,stack<int> &st,vector<bool> &vis){
    vis[sr]=true;
    //cout<<sr<<endl;
    for(int i=0;i<graph[sr].size();i++){
        //cout<<graph[sr][i]<<" "<<vis[graph[sr][i]]<<endl;
        if(!vis[graph[sr][i]]){
            topological(graph,graph[sr][i],st,vis);
        }
    }
    st.push(sr);
    
}

void solve(){
creategraph();
display();

vector<bool> vis(n,false);
stack<int> st;
for (int i = 0; i < n; i++){ 
      if (!vis[i]) 
        topological(graph,i,st,vis);
}
 
while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();

}

}



int main(){
solve();
return 0;
}