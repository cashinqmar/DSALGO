#include<bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int>& prices) {

if(k>prices.size()/2){
    k=ceil((float)prices.size()/2);
}

vector<int> tik_0(k+1,0);
vector<int> tik_1(k+1,INT_MIN);

for(int i=0;i<prices.size();i++){
    for(int j=1;j<=k;j++){
        tik_0[j]=max(tik_0[j],tik_1[j]+prices[i]);
        tik_1[j]=max(tik_1[j],tik_0[j-1]-prices[i]);
    }
}
return tik_0[k];
}

int main(){

}
