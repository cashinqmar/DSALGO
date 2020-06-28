#include<bits/stdc++.h>
using namespace std;



int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    unordered_map<int,int> m;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]]=max(m[arr[i]],m[arr[i]-1]+1);
        ans=max(ans,m[arr[i]]);
    }
    cout<<n-ans<<"\n";

}
}