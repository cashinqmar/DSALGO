#include<bits/stdc++.h>
using namespace std;

string str1="send";
string str2="more";
string str3="money";
string ans;
int vis=0;
vector<int> mapping(26,0);
int digits(int n){
    int count=0;
    while(n){
        n=n/10;
        count++;
    }
    return count;
}
int getintfromstring(string str){
    int res=0;
    for(int i=0;i<str.length();i++){
        res=10*res+mapping[str[i]-'a'];
    }
    return res;
}

int solve(string str,int idx){
    if(idx==str.length()){
        int a=getintfromstring(str1);
        int b=getintfromstring(str2);
        int c=getintfromstring(str3);
        if((a+b==c)&&(digits(a)==str1.length())&&(digits(b)==str2.length())&&(digits(c)==str3.length())){
            cout<<a<<" "<<b<<" "<<c<<endl;
            return 1;
        }
        return 0;
    }

    int count=0;
    int ch=str[idx]-'a';
    for(int i=9;i>=0;i--){
        int mask=(1<<i);
     if((vis&(mask))==0){
         vis^=mask;
         mapping[ch]=i;
         count+=solve(str,idx+1);
         mapping[ch]=0;
         vis^=mask;
     }
    }
    return count;
}

void crypto(){
    string str=str1+str2+str3;
    int freq[26]={0};
    for(int i=0;i<str.length();i++){
        freq[str[i]-'a']++;
    }
   // for(int i=0;i<26;i++)cout<<freq[i];
    cout<<endl;
    for(int i=0;i<26;i++){
        if(freq[i]!=0)ans+=(char)(i+'a');
    }
    cout<<solve(ans,0);
}
int main(){
    crypto();
    return 0;

}