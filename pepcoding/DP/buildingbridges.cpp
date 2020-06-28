#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> &nums){
    int n=nums.size();
    vector<int> arr(n,0);
    int ans=0;

    for(auto val:nums){
        int lo=0;
        int hi=ans;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(arr[mid]<=val){
                lo=mid+1;
            }
            else
            {
                hi=mid;
            }
            
        }

        if(lo==ans)ans++;
        arr[lo]=val;
    }
    return ans;
}

int buildbridges(vector<vector<int>> &bridges){
    sort(bridges.begin(),bridges.end(),[](vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    });

    vector<int> arr(bridges.size(),0);
    for(int i=0;i<bridges.size();i++){
        arr[i]=bridges[i][1];
    }

    return lis(arr);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
         vector<vector<int>> bridges(n,vector<int> (2,0));
         for(int i=0;i<n;i++){
             cin>>bridges[i][0];
             
         }
          for(int i=0;i<n;i++){
             cin>>bridges[i][1];
             
         }
    cout<<buildbridges(bridges)<<"\n";
    }
}