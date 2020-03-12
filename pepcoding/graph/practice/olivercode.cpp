#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#define max_nodes 100001
using namespace std;

list<int> G[max_nodes];

bool visited[max_nodes];
int jump_parent[max_nodes],depth[max_nodes],parent[max_nodes],dist[max_nodes];
int size;

int LCANaive(int u,int v)
{
if (u == v) return u;

if (depth[u] > depth[v])
swap(u,v);
v = parent[v];

return LCANaive(u,v);
}


void addEdge(int u,int v)
{
G[u].push_back(v);
}


int bfsheight(int v,int n) //in order to find the height of the N-Ary Tree
{

list<int>queue;
queue.push_back(v);
dist[v]=1;
list<int>::iterator i;
while(!queue.empty())
{
v=queue.front();
queue.pop_front();
for(i=G[v].begin();i!=G[v].end();i++)
{
if(!visited[*i])
{
dist[*i]=dist[v]+1;
visited[*i]=true;
queue.push_back(*i);
}

}
}


int *it;
it=max_element(dist,dist+n);
return *it;

}


void dfs(int cur,int prev)
{
depth[cur]=depth[prev]+1;
parent[cur]=prev;
if(depth[cur]%size==0)
jump_parent[cur]=parent[cur];
else
jump_parent[cur]=jump_parent[prev];


list<int>::iterator i;
for(i=G[cur].begin();i!=G[cur].end();i++)
{
if(*i!=prev)
dfs(*i,cur);
}
}

int LCASQRT(int u,int v)
{
while(jump_parent[u]!=jump_parent[v])
{
if(depth[u]>depth[v])
{
swap(u,v);
}
v=jump_parent[v];
}
return LCANaive(u,v);
}
void preprocess(int height)
{
size = sqrt(height);
depth[0] = -1;

// precalclating 1)depth. 2)parent. 3)jump_parent
// for each node
dfs(1, 0);
}
int main()
{
ios::sync_with_stdio(false);
cin.tie(false);
cout.tie(false);
int nodes;cin>>nodes;int n=nodes;nodes--;
while(nodes--)
{
int a,b;cin>>a>>b;
addEdge(a,b);
}
memset(visited,false,sizeof(visited));
memset(dist,0,sizeof(dist));

int height=bfsheight(1,n);
preprocess(height);
int q;cin>>q;
while(q--)
{
int t,a,b;cin>>t>>a>>b;
int lca=LCASQRT(a,b);
if(t==0)
{
if(( lca ==a))
{
cout<<"YES\n";
}
else
cout<<"NO\n";
}
else
{
if(lca==b)
cout<<"YES\n";
else
cout<<"NO\n";
}
}
return 0;
}