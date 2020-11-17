#include<bits/stdc++.h>
using namespace std;

bool check(string &str,int &k,bool &sign){
        int i=0;
        for(;i<str.size();i++){
            if(str[i]!=' '){
             break;
            }
        }

    k=i;
    if(str[i]=='+'||str[i]=='-'||(str[i]>='0'&&str[i]<='9')){}
    else return false;

    if(str[i]=='+')sign=true;
    if(str[i]=='-')sign=true;
    
    return true;
}

long long int atooi(string str,int id){
    long long int ans=0;
    int k=0;
    for(int i=str.size()-1;i>=0;i--){
        long long int temp=str[i]-'0';
        ans=ans+(long)(pow(10,k))*temp;
        if(ans*id>=INT_MAX)return INT_MAX;
        if(ans*id<=INT_MIN)return INT_MIN;
        
        k++;
    }
    cout<<ans;
    return ans*id;
}
    

int myAtoi(string str) {
int k;
bool sign=false;
if(!check(str,k,sign))return 0;


string workable="";

char ch;
if(sign){ch=str[k];k++;}
    
for(int i=k;i<str.size();i++){
    if(str[i]>='0'&&str[i]<='9')workable+=str[i];
    else break;
}
string newworkable="";
for(int i=0;i<workable.size();i++){
    if(workable[i]!='0'){newworkable=workable.substr(i);break;}
}


int id=(ch=='-')?-1:1;
    
if(newworkable.size()<=10)
return atooi(newworkable,id);

return (ch=='-')?INT_MIN:INT_MAX;
}
int main(){

}