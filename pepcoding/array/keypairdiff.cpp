#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
  int n,k;
  cin>>n>>k;
  vector<int> arr(n,0);
  for (int i = 0; i < n; i++)
  {
      cin>>arr[i];
  }

  sort(arr.begin(),arr.end());
  int i=0;
  int j=1;
  bool ans=false;
  while(i<j&&j<n){
      if(arr[j]-arr[i]==k){
          ans=true;
          break;
      }
    else  if(arr[j]-arr[i]<k){
          j++;
      }
      else{
          i++;
      }
  }
  if(ans)cout<<"1"<<"\n";
  else cout<<"-1"<<"\n";
  
}
}