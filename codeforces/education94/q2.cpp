#include<bits/stdc++.h>
using namespace std;


void solve(){
string s;
cin>>s;
long long  k;
cin>>k;

bool result=true;
string ans="";


if(s.size()==1&&k==1){
    result=false;
}
if(s.size()==0){
    result=false;
}

long long  n=s.size();
for(int i=0;i<n;i++){
    ans+='1';
}


for(long long  i=0;i<n;i++){
    if(i-k>=0){
        if(s[i]=='0'){
            ans[i-k]='0';
        }
    }
    if(i+k<n){
          if(s[i]=='0'){
            ans[i+k]='0';
        }
    }
    
}




for(long long  i=0;i<n;i++){
   if(s[i]=='1'){
       if((i-k>=0)&&(i+k<n)){
           if(ans[i-k]=='0'&&ans[i+k]=='0'){
           result=false;
           break;
           }
       }
       else if(i-k>=0){
           if(ans[i-k]=='0'){
               result=false;
               break;
           }
       }
       else if(i+k<n){
           if(ans[i+k]=='0'){
               result=false;
               break;
           }
       }
       else if((i+k>=n||i-k<0)){
           result=false;
           break;
       }

   }
}
if(result)
cout<<ans<<"\n";
else cout<<-1<<"\n";
}


int main(){
int t;
cin>>t;
while(t--){
solve();
}
}