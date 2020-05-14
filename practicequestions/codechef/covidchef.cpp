#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            arr[i]=x;
        }

        bool res=true;
        int prev=-1;
        for(int i=0;i<n;i++){
 
          if(arr[i]==1){
              if(prev==-1){
                  prev=i;
              }

              else {
                  if(i-prev<6){
                      res=false;
                      break;
                  }
                  else prev=i;
              }
          }
        }
        if(res)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}