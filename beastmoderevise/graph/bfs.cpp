#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> graph(n);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    queue<int> q;
    q.push(0);
    unordered_map<int,int> m;
    m[0]=1;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";

        for(auto i:graph[temp]){
            if(m[i]==0){
                q.push(i);
                m[i]=1;
            }
        }
    }
    cout<<"\n";
}

}