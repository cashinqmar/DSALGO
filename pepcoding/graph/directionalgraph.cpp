#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int n=8;
vector<vector<int>> graph(n,vector<int>());

void addedge(int u,int v){
    graph[u].push_back(v);
}

void display(){
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto e:graph[i]){
            cout<<e<<" ";
        }
        cout<<endl;
    }
}


void creategraph(){
    addedge(7,6); 
    addedge(7,5); 
    addedge(6,4); 
    addedge(5,4); 
    addedge(6,3); 
    addedge(5,2); 
    addedge(3,1);
    addedge(2,1);
    addedge(1,0);
    // addedge(0,7);

}

void kahnsalgo(){
    vector<int> incoming(n,0);
    for(int i=0;i<n;i++){
        for(int e:graph[i]){
          incoming[e]++;     
      }
    }

    queue<int> ans,q;
    for(int i=0;i<n;i++){
        if(incoming[i]==0)q.push(i);
    }

    while(!q.empty()){
        int temp=q.front();
        q.pop();

        ans.push(temp);
        for(int e:graph[temp]){
            if(--incoming[e]==0){
                q.push(e);
            }
        }
    }

    if(graph.size()!=ans.size()){
        cout<<" cycle is present"<<endl;
    }
    else{
        while(ans.size()!=0){
            cout<<ans.front()<<" ";
            ans.pop();
        }
    }
}

void topodfs(vector<vector<int>> &graph,int src,vector<bool>& vis,stack<int>& st){
    vis[src]=true;

    for(int i=0;i<graph[src].size();i++){
        if(!vis[graph[src][i]]){
            topodfs(graph,graph[src][i],vis,st);
        }
    }
    st.push(src);

}
void topologicalsort(vector<vector<int>> &graph){
stack<int> st;
vector<bool> vis(n,false);

for(int i=0;i<n;i++){
    if(!vis[i]){
        topodfs(graph,i, vis,st);
    }
}

while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
}

}


bool cycledfs(int src,vector<bool>& vis,vector<bool>& cycle,stack<int> & st){
    vis[src]=true;
    cycle[src]=true;

    bool res=false;
    for(int i=0;i<graph[src].size();i++){
        if(!vis[graph[src][i]]&&!res){
            res|=cycledfs(graph[src][i],vis,cycle,st);
        }
        else if(cycle[graph[src][i]])return true;
    }
    cycle[src]=false;
    st.push(src);
    return res;
}
void findcycle(){
    vector<bool> vis(n,false);
    vector<bool> cycle(n,false);

    stack<int> st;
    bool res=false;
    for(int i=0;i<n;i++)if(!vis[i])
    res|=cycledfs(i,vis,cycle,st);
    
    if(res){
        cout<<" cycle "<<endl;
    }
    else{
    while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
    }

}

}
void solve(){
creategraph();
display();
// topologicalsort(graph);
// kahnsalgo();
findcycle();
}



int main(){
solve();
return 0;
}