#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int> arr0(n,0);
    vector<int> arr1(n,0);
    arr0[0]=1;
    arr1[0]=1;
    for(int i=1;i<n;i++){
        arr0[i]=arr1[i-1]+arr0[i-1];
        arr1[i]=arr0[i-1];
    }

    cout<<arr1[n-1]+arr0[n-1]<<"\n";
}
}