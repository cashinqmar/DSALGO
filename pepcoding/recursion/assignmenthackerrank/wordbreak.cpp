#include<iostream>
#include<vector>
using namespace std;

bool isvalid(string s,vector<string>& dictionary){
    for(int i=0;i<dictionary.size();i++){
        if(s==dictionary[i])return true;
    }
    return false;
}

int wordbreak(string ques,string ans,vector<string>& dictionary){
if(ques.size()==0){
     cout<<"("<<ans.substr(0,ans.size()-1)<<")";
    return 1;
}
int count=0;

for(int i=1;i<=ques.size();i++){
    string word=ques.substr(0,i);
    if(isvalid(word,dictionary)){
        count+=wordbreak(ques.substr(i),ans+word+" ",dictionary);
    }
}
return count;
}
void solve(){
 int n;
 cin>>n;
 vector<string> dictionary;
 string s;
 for(int i=0;i<n;i++){
     cin>>s;
     dictionary.push_back(s);
 }
 string ques;
 cin>>ques;
 wordbreak(ques,"",dictionary);
}
int main(){
    solve();
    return 0;
}