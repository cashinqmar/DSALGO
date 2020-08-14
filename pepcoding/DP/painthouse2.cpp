#include<bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> &costs) {
        // write your code here
               
        
        if(costs.size()==0)
            return 0;
        
        int premin = INT_MAX;
        int smin = INT_MAX;
        
        for(int i=0;i<costs[0].size();i++)
        {
            if(costs[0][i]<premin)
            {
                smin = premin;
                premin = costs[0][i];
            }
            else if(costs[0][i]<smin)
            {
                smin = costs[0][i];
            }
        }
        
        
        for(int i=1;i<costs.size();i++)
        {
            int temp = INT_MAX;
            int temp2 = INT_MAX;
            
            for(int j=0;j<costs[i].size();j++)
            {
                
                if(costs[i-1][j]==premin)
                {
                    costs[i][j]+=smin;
                }
             
                else
                {
                    costs[i][j]+=premin;
                }
                
                if(costs[i][j]<temp)
                {
                    temp2 = temp;
                    temp = costs[i][j];
                }
                else if(costs[i][j]<temp2)
                {
                    temp2 = costs[i][j];
                }
                
                
            }
            
            premin = temp;
            smin = temp2;
            
        }
    
        return premin;
        
    }

int main(){

}