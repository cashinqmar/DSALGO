#include<bits/stdc++.h>
using namespace std;

void solve(){
int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}

for(int i=0;i<n;i+=2){
    if(arr[i]==arr[i+1])continue;
    else if(arr[i]==1&&arr[i+1]==0)arr[i]=-1;
    else if(arr[i]==0&&arr[i+1]==1)arr[i+1]=-1;
}

vector<int> newarr;
for(int i=0;i<n;i++)if(arr[i]!=-1)newarr.push_back(arr[i]);

cout<<newarr.size()<<"\n";
for(auto i:newarr)cout<<i<<" ";
cout<<"\n";

}

int main(){
int t;
cin>>t;
while(t--){
solve();
}
}