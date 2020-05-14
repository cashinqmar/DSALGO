#include<bits/stdc++.h>
using namespace std;

long long int kadane(vector<int> &arr){
   long long  int cmax=INT_MIN;
   long long  int omax=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(cmax<0)cmax=arr[i];
        else cmax+=arr[i];
        omax=max(omax,cmax);
    }
    return omax;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,k;
        cin>>n>>k;
      vector<int> arr(n,0);
      long long int x;
      long long int sum=0;
      for(int i=0;i<n;i++){
         cin>>x;
         arr[i]=x;
         sum+=x;
      }
     if(n==0||k==0){
         cout<<0<<"\n";
         continue;
     }
     long long int ans=0;

    //  cout<<kadane(arr)<<" ";
      if(k==1){
              ans=kadane(arr);
              cout<<ans<<"\n";
              continue;
          }

      if(sum>=0){
              for(int i=0;i<n;i++)arr.push_back(arr[i]);
              ans=kadane(arr)+(k-2)*sum;
              cout<<ans<<"\n";
              continue;
          }
       else{
            for(int i=0;i<n;i++)arr.push_back(arr[i]);
              ans=kadane(arr);
              cout<<ans<<"\n";
              continue;
       }        
}
}