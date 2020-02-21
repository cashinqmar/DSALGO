#include<bits/stdc++.h>
using namespace std;


bool isParenthesis(char c) 
{ 
    return ((c == '(') || (c == ')')); 
} 

bool isbalanced(string str){
    int count=0;
for(int i=0;i<str.size();i++){
    if(str[i]=='('){
        count++;
    }
    if(str[i]==')'){
        count--;
    }
    if(count<0)return false;
}
if(count!=0)return false;
return true;
}

void remove(string str,unordered_set<string>& stringset, vector<string>& ans){
    if(str.size()==0){
        return ;
    }

    if(isbalanced(str)&&(stringset.find(str)==stringset.end())){
        ans.push_back(str);
        stringset.insert(str);
        return;
    }

    for(int i=0;i<str.size();i++){
        if(!isParenthesis(str[i]))continue;
        string temp=str.substr(0,i)+str.substr(i+1);
        remove(temp,stringset,ans);
    }
    return;
}

void solve(){
    string str;
    cin>>str;
    unordered_set<string> stringset;
    vector<string> ans;
    remove(str,stringset,ans);
    int limit=-1e8;
    for (string s: ans){
        int l=s.size();
        limit=max(limit,l);
    }
    for(string s: ans){
        int l=s.size();
    if(limit==l)cout<<s<<endl;
    }
    
}
int main(){
    solve();
    return 0;
}