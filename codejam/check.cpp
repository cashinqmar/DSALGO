#include<bits/stdc++.h>
using namespace std;

int main(){
    string n;
    cin>>n;
 stringstream ss(n);
 string temp;
//  stack<string> st;
int ctr=0;

string ans="";
 while(getline(ss,temp,'0')){
     ans=ans+"("+temp+")"+"0";
 }

cout<<ans.substr(0,ans.size()-1);
}