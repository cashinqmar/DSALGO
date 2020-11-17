#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]]++;
    }
    if(m[0]==0){cout<<0<<"\n";return;}

    unordered_map<int,int> m1,m2;

    for(int i=0;i<=100;i++){
        if(m[i]>0){
            m1[i]++;
            m[i]--;
        }
        else break;
    }

       for(int i=0;i<=100;i++){
        if(m[i]>0){
            m2[i]++;
            m[i]--;
        }
        else break;
    }
    int count1,count2;
    for(int i=0;i<=101;i++){
        if(m1[i]>0){
        }
        else {count1=i;break;}
    }
     for(int i=0;i<=101;i++){
        if(m2[i]>0){
        }
        else {count2=i;break;}
    }
    cout<<count1+count2<<"\n";

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}