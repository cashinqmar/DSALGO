#include<bits/stdc++.h>
using namespace std;


int main(){
int t;
cin>>t;
while(t--){
int n;
cin>>n;

unordered_map<long long int,int> xmap;
unordered_map<long long int,int> ymap;
unordered_map<string,int> m;
long long int x,y;
long long int ans=0;
for(int i=0;i<n;i++){
    cin>>x>>y;
    string str=to_string(x)+"x"+to_string(y);
    ans+=xmap[x]+ymap[y]-2*m[str];
    xmap[x]++;
    ymap[y]++;
    m[str]++;
}
cout<<ans<<"\n";
}
}