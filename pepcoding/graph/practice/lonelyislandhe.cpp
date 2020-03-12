#include<bits/stdc++.h>
using namespace std;

vector<int> graph[200005];
vector<double> val(200005);
vector<int> incoming(200005);
vector<int> out(200005);
#define eps 1e-9
int n,m,r;
void kahns(){
// multiset<int> q or pq for increasing order topo
queue<int> q;
    for(int i=1;i<=n;i++)if(incoming[i]==0)q.push(i);

    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(auto i:graph[top]){
            if(--incoming[i]==0)q.push(i);
            val[i]+=val[top]/out[top];
         
    }

}
}
int main(){
    cin>>n>>m>>r;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        incoming[y]++;
        out[x]++;
    }     val[r]=1.0;
          kahns();
 double maxx=0.0;
    for(int i=1;i<=n;i++)
    if(!out[i])
        maxx=max(maxx,val[i]);
    
    for(int i=1;i<=n;i++){
     
		if(!out[i] && fabs(val[i]-maxx)<=eps)
		{
			cout<<i<<" ";
		}
	}
}