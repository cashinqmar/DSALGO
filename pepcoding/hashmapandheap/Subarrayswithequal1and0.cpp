#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        unordered_map<int,int> m;
        m[0]=1;
        int len=0;
        int sum=0;
        for(int i=0;i<n;i++){
        if(arr[i]==1)sum++;
        else sum--;

         m[sum]++;
    }

    int count=0;
    for(auto i:m)count+=((i.second)*(i.second-1))/2;

    cout<<count<<"\n";
}
}