#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    long ans=INT_MIN;
    for(int i=0;i<n-1;i++){
       if(ans<arr[i]+arr[i+1])ans=arr[i]+arr[i+1];
    }
    cout<<ans<<"\n";
}
}