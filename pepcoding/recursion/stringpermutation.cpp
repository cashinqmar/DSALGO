#include<iostream>
using namespace std;
int permutation01(string str,string ans){
 if(str.length()==0){
     cout<<ans<<endl;
     return 1;
 }
 int count=0;
 int seen=0;
 for(int i=0;i<str.length();i++){
     int k=str[i]-'a';
     if((seen&(1<<k))==0){
       seen|=1<<k;
     string nstr=str.substr(0,i)+str.substr(i+1);
     count+=permutation01(nstr,ans+str[i]);
 }
 }
 return count;
}
int permutation02(string str,string ans){
 if(str.length()==0){
     cout<<ans<<endl;
     return 1;
 }
 int count=0;
 for(int i=0;i<str.length();i++){
     string nstr=str.substr(0,i)+str.substr(i+1);
     count+=permutation02(nstr,ans+str[i]);
 }
 return count;
}
int main(){
cout<<permutation01("aba","");
// cout<<permutation02("aba","");
return 0;
}