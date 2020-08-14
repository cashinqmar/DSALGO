#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int ti1_0=0;
        int ti1_1=INT_MIN;
        int ti2_0=0;
        int ti2_1=INT_MIN;

        for(auto val:prices){
         ti2_0=max(ti2_0,ti2_1+val);
         ti2_1=max(ti2_1,ti1_0-val);
         ti1_0=max(ti1_0,ti1_1+val);
         ti1_1=max(ti1_1,-val);
        }
        return ti2_0;
}

int main(){

}