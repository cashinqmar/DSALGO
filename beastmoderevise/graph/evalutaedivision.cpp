#include<bits/stdc++.h>
using namespace std;

double bfs(string src,string dest,unordered_map<string,unordered_map<string,double>> &graph){

if(graph.find(src)==graph.end()){
    return -1;
}

unordered_map<string,int> vis;

queue<pair<string,double>> q;
q.push({src,1.0});
vis[src]=true;

while(!q.empty()){
    pair<string,double> temp=q.front();q.pop();
    string s=temp.first;
    double val=temp.second;

    if(s==dest)return val;

    for(auto i:graph[s]){
        if(vis.find(i.first)==vis.end()){
            q.push({i.first,i.second*val});
            vis[i.first]=true;
        }
    }
}
return -1;

}

 vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> graph;
        
        for(int i=0;i<equations.size();i++){
            graph[equations[i][0]][equations[i][1]]=values[i];
            graph[equations[i][1]][equations[i][0]]=(double)1/values[i];
        }

vector<double> ans;

for(int i=0;i<queries.size();i++){
    ans.push_back(bfs(queries[i][0],queries[i][1],graph));
}
return ans;
}
int main(){

}