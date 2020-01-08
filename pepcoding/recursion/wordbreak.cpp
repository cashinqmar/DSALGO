#include<bits/stdc++.h>
using namespace std;

bool check(string str,vector<string>& dictionary){
    for(int i=0;i<dictionary.size();i++){
        if(dictionary[i]==str)return true;
    }
    return false;
}

int wordbreak(string ques,string ans,vector<string>& dictionary){
    if(ques.size()==0){
        cout<<ans<<endl;
        return 1;
    }
int count=0;
for(int i=1;i<=ques.size();i++){
    string word=ques.substr(0,i);
    if(check(word,dictionary)){
        count+=wordbreak(ques.substr(i),ans+word+" ",dictionary);
    }
}
return count;
}

   int main(){
       vector<string> dictionary={"i","like","ice","cream","icecream","and","mango","man","go"};
        string str="ilikeicecreamandmango";

       cout<<wordbreak(str,"",dictionary);
       return 0;
   } 