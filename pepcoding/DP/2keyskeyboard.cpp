#include<bits/stdc++.h>
using namespace std;

int minSteps(int n) {
int ans=0;

if(n%2==0){
    n=n/2;
    ans+=2;
}

for(int i=3;i<sqrt(n);i++){
        n=n/i;
        ans+=i;
    }
}

if(n>2){
    ans+=n;
}

return ans;

}

int main(){

}