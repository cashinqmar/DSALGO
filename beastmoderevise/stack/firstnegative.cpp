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
        int k;
        cin>>k;

        int negative=n;
        vector<int> dis(arr.size()-k+1);

              int last=dis.size()-1;
        for(int i=n-1;i>=0;i--){
            if(arr[i]<0)negative=i;

            if(i+k-1<n){
                if(negative<i+k)
                dis[last--]=arr[negative];
                else dis[last--]=0;
            }
        }
        for(auto i:dis)cout<<i<<" ";
        cout<<"\n";
    }
}