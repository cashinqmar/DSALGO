#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int ctr=0;
    while(ctr++<t){
        string  n;
        cin>>n;
        
        int prev=0;
        cout<<"Case #"<<ctr<<": ";
        for(int i=0;i<n.size();i++){
          int a=prev-(n[i]-'0');
          if(a<0){
              for(int i=0;i<abs(a);i++)cout<<"(";
          }
          else{
               for(int i=0;i<abs(a);i++)cout<<")";
          }
          cout<<n[i];
          prev=n[i]-'0';
      }

      for(int i=0;i<prev;i++)cout<<")";

      cout<<"\n";
        }

}


