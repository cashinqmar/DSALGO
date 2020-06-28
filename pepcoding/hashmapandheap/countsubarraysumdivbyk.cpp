#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];

        unordered_map<int,int> m;
        int prefix=0;
        m[0]=1;
        int count=0;
        for(int i=0;i<n;i++){
            prefix+=arr[i];
            int rem=prefix%k;
            if(rem<0)rem+=k;

            if(m.find(rem)==m.end())m[rem]++;
            else{count+=m[rem];m[rem]++;
            }
        }

        cout<<count<<"\n";
    }
}