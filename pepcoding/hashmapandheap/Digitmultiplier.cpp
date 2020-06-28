#include<bits/stdc++.h>
using namespace std;

string ans="";
void funct(long long n,int i){
    while(i>1){
        if(n%i==0){ans=to_string(i)+ans;
                    break;
        }
        i--;
    }
    if(n/i==1)return;
    if(i==1){
        ans="-1";
        return;
    }
    funct(n/i,i);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        ans="";
        funct(n,9);
        if(n==1)cout<<1<<"\n";
        else cout<<ans<<"\n";
    }
}