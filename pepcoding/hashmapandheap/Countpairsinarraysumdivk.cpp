#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        
        unordered_map<int,int> m;
        int rem;
        int ans=0;
        for(int i=0;i<n;i++){
            rem=arr[i]%4;
            if(rem<0)rem+=4;

            int k=4-rem;
            if(k==4)k=0;

            ans+=m[k];
            m[rem]++;
        }
        cout<<ans<<"\n";
    }
}