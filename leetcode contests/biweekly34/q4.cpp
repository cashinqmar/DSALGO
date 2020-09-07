#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>& locations,int start,int finish,int fuel,  vector<vector<int>> &dp){
    if(dp[start][fuel]!=-1){
        return dp[start][fuel];
    }
     if(start==finish){
       return dp[start][fuel]=1;
    }
    int total=0;
    for(int i=0;i<locations.size();i++)
        if(start!=i){
            if(fuel-abs(locations[start]-locations[i])>=0)){
                total=(total%1000000007+helper(locations,i,finish,fuel-abs(locations[start]-locations[i])%1000000007))%1000000007;
        }
    return dp[start][fuel]=total;
}
}
                       

int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(),vector<int>(fuel+1,-1));
    
        int count=helper(locations,start,finish,fuel,dp);
        return count;
}



int main(){

}