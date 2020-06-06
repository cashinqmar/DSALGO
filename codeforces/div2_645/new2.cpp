#include<bits/stdc++.h>
using  namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
      ll x1,y1,x2,y2;
      cin>>x1>>y1>>x2>>y2;

      if(x1==x2||y1==y2)cout<<1<<"\n";
      else{
          int n=x2-x1;
          int m=y2-y1;
          int max1=max(m,n);
          int min1=min(m,n);
          if(max1==min1)cout<<max1+1<<"\n";
          else cout<<2*(max1-min1)+1<<"\n";
      }
     }

    return 0;
}