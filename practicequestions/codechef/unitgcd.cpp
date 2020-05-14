#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;cin>>x;
        if(x==1){
            cout<<1<<"\n";
            cout<<1<<" "<<1<<'\n';
        }

       else if(x%2==0){
            int n=x/2;
            cout<<n<<"\n";
            int k=1;
            for(int i=0;i<n;i++){
                cout<<"2"<<" "<<k<<" "<<k+1<<"\n";
                k+=2;
            }
        }
        else{
            int n=x/2;
            cout<<n<<"\n";
            n=n-1;
            int k=1;
             for(int i=0;i<n;i++){
                cout<<"2"<<" "<<k<<" "<<k+1<<"\n";
                k+=2;
            }
            cout<<3<<" "<<k<<" "<<k+1<<" "<<x<<"\n";

        }
    }
}

