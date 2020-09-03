#include<bits/stdc++.h>
using namespace std;





void solve(){
long long p,f,s,w,cns,cnw;
cin>>p>>f>>cns>>cnw>>s>>w;

if(s>w){swap(s,w);swap(cns,cnw);}
int ans=0;
for(int i=0;i<=cns;i++){
    if(i*s>p)break;
    int j=min(cnw,(p-s*i)/w);
    int k=min(cns-i,f/s);
    int l=min(cnw-j,(f-k*s)/w);
    ans=max(ans,i+j+k+l);
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