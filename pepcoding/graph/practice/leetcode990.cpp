#include<bits/stdc++.h>
using namespace std;

char root(unordered_map<char,char> &par,char ch){
    if(ch==par[ch])return ch;
    return par[ch]=root(par,par[ch]);
}

void merge(unordered_map<char,char> &par,char x,char y){
    char a=root(par,x);
    char b=root(par,y);
    if(a!=b){
        par[a]=b;
    }
}


bool equationsPossible(vector<string>& eq) {
unordered_map<char,char> par;

for(int i=0;i<eq.size();i++){
    if(eq[i][1]=='='){
      merge(par,eq[i][0],eq[i][3]);
    }
}
for(int i=0;i<eq.size();i++){
    if(eq[i][1]=='!'){
     char a=root(par,eq[i][0]);
     char b=root(par,eq[i][3]);
     if(a==b)return false;
    }
}
return true;
}
int main(){

}