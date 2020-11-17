// please no hack please bhai maanja bhai please hack mat kr yar please no hack pls :(
#include<bits/stdc++.h>
using namespace std;

int main() {
 
      int n;cin>>n;
      int l=1 , r=n;
      vector<int>ans(n,0);
      unordered_set<int>used;
      for(int i=0 ; i< n ; i++ ){
         if(l==r){
            break;
         }
         cout<<"? "<<l<<" "<<r<<endl;
         int k1;
         cin>>k1;
         cout<<"? "<<r<<" "<<l<<endl;
         int k2;
         cin>>k2;
         if(k1 < k2){
            ans[r-1]=k2;
            used.insert(k2);
            r--;
         }else{
            ans[l-1]=k1;
            used.insert(k1);
            l++;
         }
      }
      for(int i=1;i<=n ; i++){
         if(!used.count(i)){
            ans[l-1]=i;
            break;
         }
      }
      cout<<"! ";
      for(int i=0 ; i<n ; i++)cout<<ans[i]<<" ";
      cout<<endl;

      return 0;
   
} 