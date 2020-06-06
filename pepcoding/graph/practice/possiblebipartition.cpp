#include<bits/stdc++.h>
using namespace std;


 bool bfs(int src,vector<int> &visited,vector<vector<int>> &graph ,vector<int> &color){
    queue<pair<int,int>> q;
     q.push({src,0});
     color[src]=0;
     visited[src]=1;

     while(!q.empty()){
         pair<int,int> temp=q.front();q.pop();
         int v=temp.first;
         int col=temp.second;

         for(auto i:graph[v]){
             if(visited[i]==-1){
                 q.push({i,(col+1)%2});
                 visited[i]=1;
                 color[i]=(col+1)%2;
             }
             else{
                 if(color[i]==col)return false;
             }
         }
     }
     return true;
 }

 bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(int i=0;i<dislikes.size();i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
              graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }

     vector<int> color(n+1,-1);
     vector<int> visited(n+1,-1);

     for(int i=1;i<=n;i++){
         if(visited[i]==-1){
             if(bfs(i,visited,graph,color)==false)return false;
         }
     }
     return true;
}
int main(){

}