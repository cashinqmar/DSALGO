#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'minCostPath' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. WEIGHTED_INTEGER_GRAPH g
 *  2. INTEGER x
 *  3. INTEGER y
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int minCostPath(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight, int n1, int n2) {

    if(n1>n2)swap(n1,n2);
   vector<vector<pair<long int,long int>>> graph(100005);
    vector<bool> visited(100005,false);
     vector<int> ans(100005,0);
for(int i=0;i<g_from.size();i++){
    int x=g_from[i];
    int y=g_to[i];

    graph[x].push_back({y,g_weight[i]});
    graph[y].push_back({x,g_weight[i]});
}

 auto comp=[](pair<long int,long int> &a,pair<long int,long int>&b){
       return a.second>b.second;
   };

    priority_queue<pair<long int,long int>,vector<pair<long int,long int>>,decltype(comp)> pq(comp);
    
    long long int sum=0;

    pq.push({1,0});
    while(!pq.empty()){
        pair<long int,long int> t=pq.top();
        pq.pop();

        int v=t.first;
        int w=t.second;
        if(visited[v])continue;
        ans[v]=w;
        visited[v]=true;
        for(int i=0;i<graph[v].size();i++){
            if(!visited[graph[v][i].first]){
             pq.push({graph[v][i].first,graph[v][i].second+w});
            }
        }
    }

    sum+=ans[n1];
    for(int i=1;i<=g_nodes;i++){
   visited[i]=false;
   ans[i]=0;
}
  priority_queue<pair<long int,long int>,vector<pair<long int,long int>>,decltype(comp)> pq1(comp);
    
     pq1.push({n1,0});
     
    while(!pq1.empty()){
        pair<long int,long int> t=pq1.top();
        pq1.pop();

        int v=t.first;
        int w=t.second;
    
        if(visited[v])continue;
        ans[v]=w;
        visited[v]=true;
        for(int i=0;i<graph[v].size();i++){
            if(!visited[graph[v][i].first]){
             pq1.push({graph[v][i].first,graph[v][i].second+w});
            }
        }
    }
    sum+=ans[n2];
for(int i=1;i<=g_nodes;i++){
   visited[i]=false;
   ans[i]=0;
}
  priority_queue<pair<long int,long int>,vector<pair<long int,long int>>,decltype(comp)> pq2(comp);
     visited[g_nodes]=false;

     pq2.push({n2,0});
    while(!pq2.empty()){
        pair<long int,long int> t=pq2.top();
        pq2.pop();

        int v=t.first;
        int w=t.second;
       
        if(visited[v])continue;
        ans[v]=w;
        visited[v]=true;
        for(int i=0;i<graph[v].size();i++){
            if(!visited[graph[v][i].first]){
             pq2.push({graph[v][i].first,graph[v][i].second+w});
            }
        }
    }

sum+=ans[g_nodes];

for(int i=1;i<=g_nodes;i++){
    cout<<ans[i]<<" ";
}
return sum;

}

int main(){
    
}