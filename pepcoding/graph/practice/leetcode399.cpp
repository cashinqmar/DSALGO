#include<bits/stdc++.h>
using namespace std;

double bfs(unordered_map<string,unordered_map<string,double>> &graph,string src,string des){

if(graph.find(src)==graph.end()&&graph.find(des)==graph.end()){
    return -1;
}

if(src==des)return 1;

double val;

unordered_map<string,int> visited;
queue<pair<string,double>> q;
q.push({src,1.0});
visited[src]++;
while(!q.empty()){

pair<string,double> temp=q.front();q.pop();
string node=temp.first;
double val=temp.second;

if(des==node)return val;

for(auto i:graph[node]){
if(visited[i.first]==0){
    q.push({i.first,i.second*val});
    visited[i.first]++;
}
}
}
return -1;
}

double ans=-1;
void dfs(unordered_map<string,unordered_map<string,double>> &graph,string src,string des,unordered_map<string,int> &visited,double val){
if(src==des){
    ans=val;
    return;
}

visited[src]++;
for(auto i:graph[src]){
    if(visited[i.first]==0){
        dfs(graph,i.first,des,visited,val*i.second);
    }
}

}

double evaluate(unordered_map<string,unordered_map<string,double>> &graph,string src,string des){
    
if(graph.find(src)==graph.end()&&graph.find(des)==graph.end()){
    return -1;
}

if(src==des)return 1;

double val=1;

unordered_map<string,int> visited;
ans=-1;
dfs(graph, src, des,visited,val);
return ans;
}

 vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> graph;
        
        for(int i=0;i<equations.size();i++){
            graph[equations[i][0]][equations[i][1]]=values[i];
            graph[equations[i][1]][equations[i][0]]=(double)(1/values[i]);
        }

vector<double> res;

for(int i=0;i<queries.size();i++){

    res.push_back(bfs(graph,queries[i][0],queries[i][1]));
}
return res;
}

int main(){


}