#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,wt;
        cin>>n>>wt;
        vector<pair<float,pair<int,int>>> arr(n);

        for(int i=0;i<n;i++){
            int val,w;
            cin>>val>>w;
            float ratio=(float)val/(float)w;
            arr[i]={ratio,{w,val}};
        }
        sort(arr.begin(),arr.end(),[](pair<float,pair<int,int>> &a,pair<float,pair<int,int>> &b){
            return a.first>b.first;
        });

        // for(auto i:arr){
        //     cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<" ";
        // }
        // cout<<"\n";

        double ans=0;
        int k=0;
        while(k<n&&wt>0){
            if(wt>=arr[k].second.first){
            // cout<<wt<<" ";

            ans+=arr[k].second.second;
            wt=wt-arr[k].second.first;
            k++;

            }
            else{
            // cout<<wt<<" ";

              ans+=wt*arr[k].first;
              k++;
              wt=0;
            }
        }
        cout<<fixed<<setprecision(2)<<ans<<"\n";
    }
}