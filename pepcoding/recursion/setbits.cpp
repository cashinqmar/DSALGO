#include<bits/stdc++.h>
using namespace std;

int countsetbits(int n){
    if(n==0)return 0;
    int ans=1+countsetbits(n&(n-1));
    return ans;
}
/*int countsetbits(int n){
    int count=0;
    while(n!=0){
         n=n&(n-1);
         count++;
    }
    return count;
}*/

int main(){
int a;
cin>>a;
cout<<countsetbits(a);
}