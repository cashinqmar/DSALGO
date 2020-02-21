#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};
void addEdge(vector<vector<Edge *>> & graph,int u, int v, int w)
{
    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

bool hamintonianPath(vector<vector<Edge *>> & graph,int src, int osrc, vector<bool> &vis, int count)
{
    int l=graph.size();
    if (count == l-1)
    {
        return true;
    }
bool res=false;
    vis[src] = true;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
        {
            // cout<<src<<" ";
           res|= hamintonianPath(graph,e->v, osrc, vis, count + 1);
        }
    }
    vis[src] = false;

    return res;
}


int main(){
    int t;
    cin>>t;
    while(t--){
    int x,y;
    cin>>x>>y;
 int n=x;
vector<vector<Edge *>> graph(n,vector<Edge*>());
vector<bool> visited(n,false);
   int a,b;
        for(int j=0;j<y;j++){
            cin>>a>>b;
            addEdge(graph,a-1,b-1,1);
        }
    
   if(hamintonianPath(graph,a,a,visited,0))cout<<1<<endl;
   else cout<<0;
}
}