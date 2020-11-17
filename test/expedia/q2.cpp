#include<bits/stdc++.h>
using namespace std;

vector<string> removespace(string &str){
vector<string> ans;

string s="";

for(int i=0;i<str.size();i++){

    if(str[i]!=' '){
        s+=str[i];
    }
 
    else{
        ans.push_back(s);
        s="";
    }
}
ans.push_back(s);

return ans;
}

string givemonth(string s){
    if(s=="Jan")return "01";
    if(s=="Feb")return "02";
    if(s=="Mar")return "03";
    if(s=="Apr")return "04";
    if(s=="May")return "05";
    if(s=="Jun")return "06";
    if(s=="Jul")return "07";
    if(s=="Aug")return "08";
    if(s=="Sep")return "09";
    if(s=="Oct")return "10";
    if(s=="Nov")return "11";
    if(s=="Dec")return "12";
    return "";
}

string process(vector<string> &myarr){
    string ans="";
   string date="";
   for(int i=0;i<myarr[0].size();i++){
       if(myarr[0][i]-'0'<0||myarr[0][i]-'0'>9)break;
       else date+=myarr[0][i];
   }
   if(date.size()==1)date="0"+date;

    
    ans="-"+date+ans;
    ans="-"+givemonth(myarr[1])+ans;
    ans=myarr[2]+ans;
    return ans;
}

vector<string> preprocessDate(vector<string> &dates) {

vector<string> withoutspace;
for(int i=0;i<dates.size();i++){
    vector<string> temp=removespace(dates[i]);
    string newmy=process(temp);
    withoutspace.push_back(newmy);
}
return withoutspace;
}
