#include<bits/stdc++.h>
using namespace std;
  
string number4(int n){
   vector<string> arr={"","M","MM","MMM","MD","","M","MM","MMM","MM"};
   return arr[n];
}
string number3(int n){
   vector<string> arr={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
   return arr[n];
}
string number2(int n){
   vector<string> arr={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
   return arr[n];
}
string number1(int n){
   vector<string> arr={"","I","II","III","IV","V","VI","VII","VIII","IX"};
   return arr[n];
}
string intToRoman(int num) {

string ans="";
int k=0;
while(num>0){

int temp=num%10;
num=num/10;

if(k==0){
    ans=number1(temp)+ans;
}
if(k==1){
    ans=number2(temp)+ans;
}

if(k==2){
    ans=number3(temp)+ans;
}

if(k==3){
    ans=number4(temp)+ans;
}
k++;
}

return ans;

}

int main(){

}