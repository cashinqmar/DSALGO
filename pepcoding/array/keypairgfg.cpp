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
  int j=n-1;
  bool ans=false;
  while(i<j){
      if(arr[i]+arr[j]==k){
          ans=true;
          break;
      }
    else  if(arr[i]+arr[j]<k){
          i++;
      }
      else{
          j--;
      }
  }
  if(ans)cout<<"YES"<<"\n";
  else cout<<"NO"<<"\n";
  
}
}