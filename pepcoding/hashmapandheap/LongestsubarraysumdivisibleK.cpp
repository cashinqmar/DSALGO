#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        unordered_map<int,int> m;

        int len=0;
        int sum=0;
        for(int i=0;i<n;i++){
        sum+=arr[i];
        int rem=sum%k;
        if(m.count(rem)==0)m[rem]=i;

        len=max(len,i-m[rem]);
    }

    cout<<len<<"\n";
}
}