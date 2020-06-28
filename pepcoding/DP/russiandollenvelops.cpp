#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> &nums){
int ans=0;
int n=nums.size();
vector<int> arr(n,0);

for(auto val:nums){
    int lo=0;
    int hi=ans;

    while(lo<hi){
        int mid=(lo+hi)/2;
        if(arr[mid]<val){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    arr[lo]=val;
    if(lo==ans)ans++;
}
return ans;
}
int maxEnvelopes(vector<vector<int>>& envelopes) {

    int n=envelopes.size();

    sort(envelopes.begin(),envelopes.end(),[](vector<int>&a,vector<int>&b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    })    ;

    vector<int> arr(n,0);

    for(int i=0;i<n;i++){
        arr[i]=envelopes[i][1];
    }    

    return lis(arr);
}

int main(){

}