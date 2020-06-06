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
      cin>>n;
      vector<ll> arr(n);
      for(int i=0;i<n;i++)cin>>arr[i];
     sort(arr.begin(),arr.end());
      ll total=1;
      ll k=-1;
      ll ans=1;
      for(ll i=0;i<n;i++){
        if(total>=arr[i]){
             ans+=i-k;
            k=i;
        }
        total++;
      }
      cout<<ans<<"\n";
     }

    return 0;
}