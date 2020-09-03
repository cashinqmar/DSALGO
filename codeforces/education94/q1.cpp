#include<bits/stdc++.h>
using namespace std;

#define long long ll

void sumstring(string &ans,string &s){
    for(int i=0;i<s.size();i++){
        if(ans[i]=='1'||s[i]=='1'){
            ans[i]='1';
        }
    }
    return;
}

void solve(){
int n;
cin>>n;
string s;
cin>>s;

string ans="";
for(int i=0;i<n;i++){
    ans+='0';
}
for(int i=0;i<n;i++){
    string a=s.substr(i,n);
sumstring(ans,a);
}
cout<<ans<<"\n";
}


int main(){
int t;
cin>>t;
while(t--){
solve();
}
}