#include<bits/stdc++.h>
using namespace std;

bool partition(vector<int>& arr,int k,int curr,int tar,int idx,vector<bool> &visited){
    if(k-1==0){
        return true;
    }

    if(curr==tar){
     return partition(arr,k-1,0,tar,idx,visited);
    }

for(int i=idx;i<=arr.size();i++){
    if(!visited[i]&&curr+arr[i]<=tar){
        visited[i]=true;
        if( partition(arr,k,curr+arr[i],tar,idx+1,visited)) return true;
        visited[i]=false;
    }
    }
    return false;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
int k;
cin>>k;
if(sum%k!=0)cout<<"No"<<endl;
else{
    vector<bool> visited(n,false);
  if(partition(arr,k,0,sum/k,0,visited))cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
}
int main(){
    solve();
    return 0;
}

