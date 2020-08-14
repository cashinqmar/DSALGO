#include<bits/stdc++.h>
using namespace std;
    
int maxProfit(vector<int>& prices) {
        int tik0=0;
        int tik1=INT_MIN;

        for(int i=0;i<prices.size();i++){
            int temp=tik0;
            tik0=max(tik0,tik1+prices[i]);
            tik1=max(tik1,temp-prices[i]);
        }
        return tik0>0?tik0:0;
}

int main(){

}