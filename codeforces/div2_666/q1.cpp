#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,t;
    cin>>n;
    t=n;
    unordered_map<int,int> m;
    while(n--){
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++){
            m[s[i]-'a']++;
        }
    }

    bool ans=true;

    for(int i=0;i<26;i++){
        if(m[i]%t!=0){
            ans=false;
            break;
        }
    }
    if(ans)cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}