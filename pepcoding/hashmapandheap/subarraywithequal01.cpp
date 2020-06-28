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
        int one=0;
        int zero=0;
        unordered_map<int,int> m;
        int ans=0;
        m[0]=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1)one++;
            else zero++;

            int diff=zero-one;
            ans+=m[diff];
            m[diff]++;
        }
        cout<<ans<<"\n";
    }
}