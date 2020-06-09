#include<bits/stdc++.h>
using namespace std;

int root(vector<int> &par,int vtx){
    if(vtx==par[vtx])return vtx;
    return par[vtx]=root(par,par[vtx]);
}



int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    
   vector<pair<int,int>> arr(n);
    int x,y,z;
    int maxm=0;
    for(int i=0;i<n;i++){
       cin>>x>>y>>z;
       maxm=max(maxm,y);
       arr[i]={y,z};
    }

    sort(arr.begin(),arr.end(),[](pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    });

    // for(auto i:par)cout<<i<<" "; 

     vector<int> par(maxm+1);
    for(int i=0;i<maxm+1;i++)par[i]=i;

int count=0;
    long long ans=0;
    for(int i=0;i<n;i++){
      int deadline=arr[i].first;
      int profit=arr[i].second;

      if(root(par,deadline)>0)
        { count++;
                  ans+=profit;
          int vtx=par[deadline];

          par[vtx]=root(par,vtx-1);
        }
    }
    cout<<count<<" "<<ans<<"\n";
    
}
}