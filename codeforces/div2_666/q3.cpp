#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007


void solve(){
    long long n;
    cin>>n;

    vector<long long> arr(n);
    vector<long long> final(n,0);

    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }

    if(n==1){
        cout<<1<<" "<<1<<"\n";
        cout<<"0"<<"\n";
        cout<<1<<" "<<1<<"\n";
        cout<<"0"<<"\n";
        cout<<1<<" "<<1<<"\n";
        cout<<-arr[0]<<"\n";
    }

else{
    cout<<1<<" "<<n-1<<"\n";
    for(long long i=0;i<n-1;i++){
        cout<<(((n-1))*arr[i])<<" ";
        final[i]+=(arr[i]+(n-1)*(arr[i]));
    }
cout<<"\n";
     cout<<1<<" "<<n<<"\n";
    for(long long i=0;i<n;i++){
        cout<<-(n)*arr[i]<<" ";
        final[i]=arr[i]-(n)*arr[i];
    }
cout<<"\n";

cout<<n<<" "<<n<<"\n";

cout<<-final[n-1]<<"\n";
}
}

int main(){

    solve();
}