#include<bits/stdc++.h>
using namespace std;

int combinationinfinite(vector<int>& arr,int tar,string ans,int idx){
    if(tar==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<arr.size();i++){
        if(tar-arr[i]>=0){
            count+=combinationinfinite(arr,tar-arr[i],ans+to_string(arr[i])+" ",i);
        }
    }
    return count;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    }
    int tar;
    cin>>tar;
   // cout<<permutationinfinite(arr,tar,"");
   combinationinfinite(arr,tar,"",0);
}

int main(){
    solve();
    return 0;
}