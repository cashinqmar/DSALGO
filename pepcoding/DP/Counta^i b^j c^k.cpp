#include<bits/stdc++.h>
using namespace std;

int main(){
   string s;
   cin>>s;

   int acount=0,bcount=0,ccount=0;
   char ch;
   for(int i=0;i<s.size();i++){
       ch=s[i];
       if(ch=='a'){
           acount=2*acount+1;
       }
       if(ch=='b'){
           bcount=2*bcount+acount;
       }
       if(ch=='c'){
           ccount=2*ccount+bcount;
       }
   }

   cout<<ccount;

}