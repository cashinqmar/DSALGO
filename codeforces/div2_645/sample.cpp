#include<bits/stdc++.h>
using  namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
      ll n;
      ll m;
      cin>>n>>m;
 
        if(m%2==0||n%2==0){
            cout<<n*m/2<<"\n";
        }
      else  if(m%2==1){
            ll ans=(n*(m-1)/2)+ceil((double(n/2)));
            cout<<ans+1<<"\n";
        }
        else{
         ll ans=(m*(n-1)/2)+ceil((double(m/2)));
            cout<<ans+1<<"\n"; 
        }
    }
    return 0;
}