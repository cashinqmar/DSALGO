#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<string,vector<string>> &m,string src,vector<string> &ans){

for(int i=m[src].size()-1;i>=0;i--){
  string temp=m[src][i];
  m[src].pop_back();
  dfs(m,temp,ans);
}
ans.push_back(src);
}


vector<string> findItinerary(vector<vector<string>>& tickets) {
unordered_map<string,vector<string>> m;

for(auto i:tickets){
    m[i[0]].push_back(i[1]);
}

for(auto i:m){
    sort(i.second.begin(),i.second.end());
}

vector<string> ans;

dfs(m,"JFK",ans);

reverse(ans.begin(),ans.end());

return ans;

}

int main(){
    vector<string> a={"JFK","ATL","SFO","ATL","JFK","SFO"};

    vector<vector<string>> tickets={{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    
    unordered_map<string,vector<string>> m;
    
    
for(auto i:tickets){
    m[i[0]].push_back(i[1]);
}

for(auto it=m.begin();it!=m.end();it++){
sort(it->second.begin(),it->second.end());
}
for(auto i:m){
    cout<<i.first<<" ";
   for(auto j:i.second)cout<<j<<" ";
    cout<<"\n";
}

}