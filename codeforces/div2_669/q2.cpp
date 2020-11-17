#include<bits/stdc++.h>
using namespace std;

void solve(){
int n;
cin>>n;

vector<int> arr(n);

int maxm=INT_MIN;
int idx=-1;
for(int i=0;i<n;i++){
cin>>arr[i];

if(maxm<arr[i]){
    maxm=arr[i];
    idx=i;
}
}

vector<int> ansarr;
ansarr.push_back(maxm);

int mygcd=maxm;

unordered_map<int,int> m;
m[idx]++;

while(ansarr.size()!=n){

int maxmgcd=INT_MIN;
int ele;

for(int i=0;i<n;i++){
    if(m[i]>0)continue;
    int k=__gcd(mygcd,arr[i]);
    if(maxmgcd<k){
        maxmgcd=k;
        ele=i;
    }
}
m[ele]++;
mygcd=maxmgcd;
ansarr.push_back(arr[ele]);
}

for(auto i:ansarr)cout<<i<<" ";
cout<<"\n";
}

int main(){
int t;
cin>>t;
while(t--){
solve();
}
}