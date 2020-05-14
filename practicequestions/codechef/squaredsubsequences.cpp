#include<bits/stdc++.h>
using namespace std;


bool check(long long a){
    if(a&1){
  return true;
    }
   if(a%4==0)return true;

   return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long int> arr(n);
        long long int x;
        for(int i=0;i<n;i++){
            cin>>x;
            arr[i]=x;
        }
long long count=0;
long long prod=1;
        for(int i=0;i<n;i++){
            prod=arr[i];
            if(check(prod))count++;
            for(int j=i+1;j<n;j++){
                prod*=arr[j];
                if(check(prod))count++;
            }
        }
         cout<<count<<"\n";
    }
}