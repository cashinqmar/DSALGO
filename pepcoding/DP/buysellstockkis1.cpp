#include<bits/stdc++.h>
using namespace std;

  int maxProfit(vector<int>& prices) {

int tik0=INT_MIN;
int tik1=INT_MIN;

for(int i=0;i<prices.size();i++){
    int val=prices[i];
    tik0=max(tik0,tik1+val);
    tik1=max(tik1,-val);
}
return tik0>0?tik0:0;
}



int main(){

}