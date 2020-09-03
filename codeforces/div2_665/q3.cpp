#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> &nums) {
    // write your code in C++14 (g++ 6.2.0)
      int n=nums.size();
       unordered_map<long long int,long long int> m;
        m[0]=1;
        long long int ans=0;
        long long int sum=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
            int s=sum;
            ans+=m[s];
            m[sum]++;
        }
        if(ans>1000000000)return -1;
        return ans;
}
