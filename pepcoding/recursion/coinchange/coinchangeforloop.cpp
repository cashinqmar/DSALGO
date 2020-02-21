#include<bits/stdc++.h>
using namespace std;

int permutationinfinite(vector<int>& arr,int tar,string ans){
    if(tar==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(tar-arr[i]>=0){
            count+=permutationinfinite(arr,tar-arr[i],ans+to_string(arr[i]));
        }
    }
    return count;
}

int combinationinfinite(vector<int>& arr,int tar,string ans,int idx){
    if(tar==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<arr.size();i++){
        if(tar-arr[i]>=0){
            count+=combinationinfinite(arr,tar-arr[i],ans+to_string(arr[i]),i);
        }
    }
    return count;
}

int permutationfinite(vector<int>& arr,int tar,string ans,int vis){
    if(tar==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<arr.size();i++){
        int mask=(1<<i);
        if(tar-arr[i]>=0&&((vis&mask)==0)){
            vis^=mask;
            count+=permutationfinite(arr,tar-arr[i],ans+to_string(arr[i]),vis);
            vis^=mask;
        }
    }
    return count;
}

int combinationfinite(vector<int>& arr,int tar,string ans,int idx){
    if(tar==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<arr.size();i++){
        if(tar-arr[i]>=0){
            count+=combinationfinite(arr,tar-arr[i],ans+to_string(arr[i])+" ",i+1);
        }
    }
    return count;
}
void solve(){
    vector<int> arr={2,3,5,7};
    int tar=10;
   // cout<<permutationinfinite(arr,tar,"");
   // cout<<combinationinfinite(arr,tar,"",0);
   // cout<<combinationfinite(arr,tar,"",0);
   cout<<permutationfinite(arr,tar,"",0);
}

int main(){
    solve();
    return 0;
}