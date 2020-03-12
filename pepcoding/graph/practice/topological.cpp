#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
    
void kahns(int n){
    vector<int> incoming(n+1,0);
    for(int i=1;i<=n;i++){
        for(auto j:graph[i])incoming[j]++;
    }

// multiset<int> q or pq for increasing order topo
queue<int> q;
vector<int> ans;

    for(int i=1;i<=n;i++)if(incoming[i]==0)q.push(i);

    while(!q.empty()){
        int top=q.front();
        q.pop();
        ans.push_back(top);
        for(auto i:graph[top])if(--incoming[i]==0)q.push(i);
    }

    for(auto i:ans)cout<<i<<" ";
}
int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
          kahns(n);

}