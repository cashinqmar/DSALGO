#include<bits/stdc++.h>
using namespace std;
bool cycle=false;

void dfs(vector<vector<int>> &graph,int src,vector<int> &visited,stack<int> &st){
    if(visited[src]==2)return;

    visited[src]=1;
    for(int i=0;i<graph[src].size();i++){
        if(visited[graph[src][i]]==0){
            dfs(graph,graph[src][i],visited,st);
        }
        else if(visited[graph[src][i]]==1){
            cycle=true;
            return;
        }
    }
    visited[src]=2;
    st.push(src);
}

vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
vector<vector<int>> graph(n);
vector<int> incoming(n);
for(int i=0;i<prerequisites.size();i++){
    graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    incoming[prerequisites[i][0]]++;
}
// vector<int> visited(n,0);
// cycle=false;
// stack<int> st;
// for(int i=0;i<n;i++){
//         dfs(graph,i,visited,st);
// }
// vector<int> res;
// if(cycle)return res;

// while(st.size()!=0){
//     res.push_back(st.top());st.pop();
// }
// return res;

queue<int> q;
for(int i=0;i<n;i++){
    if(incoming[i]==0)q.push(i);
}

vector<int> ans;
while(!q.empty()){
    int temp=q.front();
    q.pop();
    ans.push_back(temp);
    for(int i=0;i<graph[temp].size();i++){
        if(--incoming[graph[temp][i]]==0)q.push(i);
    }
}
if(ans.size()==n)return ans;
else return {};
}


}
int main(){

}