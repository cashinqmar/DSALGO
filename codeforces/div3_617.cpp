#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        int odd=0;
        int even=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x%2==0)even++;
            else odd++;
        }
        if(odd>0){
            if(n%2==0&&even==0)cout<<"NO"<<endl;
            else
            cout<<"YES"<<endl;
        }
        else cout<<"NO";
    }
}