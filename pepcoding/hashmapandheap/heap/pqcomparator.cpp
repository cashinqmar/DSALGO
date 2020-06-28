#include<bits/stdc++.h>
using namespace std;
class CustomCompare
{   public:
    bool operator()( vector<int> lhs,  vector<int>rhs)
    {
        return lhs[0] > rhs[0];
    }
};

 vector<int> smallestRange(vector<vector<int>>& nums) {
    priority_queue<vector<int>,vector<vector<int>>, CustomCompare>  pq;
    int k=nums.size();

    int maxm=INT_MIN;

    int start,end;
    for(int i=0;i<k;i++){
      pq.push({nums[i][0],i,0});
      if(maxm<nums[i][0]){
        maxm=nums[i][0];
      }
    }
    
    // cout<<maxm<<" ";

    int ans=INT_MAX;
    while(true){
      vector<int> temp=pq.top();
      pq.pop();
      int i=temp[1];
      int j=temp[2];
      if(ans>maxm-temp[0]){
        start=temp[0];
        end=maxm;
      }
      

      if(j+1==nums[i].size())break;
      else{
        maxm=max(maxm,nums[i][j+1]);
        pq.push({nums[i][j+1],i,j+1});
      }
    }
return {start,end};
  }

int main(){
vector<vector<int>> nums={{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
smallestRange(nums);
}