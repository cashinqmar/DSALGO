#include<bits/stdc++.h>
using namespace std;
int n=100000;
vector<int> arr(n,true);
void sieve(){
    for(int i=2;i*i<n;i++){
        if(arr[i]==true){
            for(int k=2*i;k<n;){
                arr[k]=false;
                k+=i;
            }
        }
    }
}

void display(int n){
    for(int i=2;i<=n;i++){
        if(arr[i])cout<<i<<" ";
    }
    cout<<"\n";
}
int main(){
int t;
cin>>t;
sieve();
while(t--){
int n;
cin>>n;
display(n);
}
}