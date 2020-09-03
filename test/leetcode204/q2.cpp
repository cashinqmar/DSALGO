#include<bits/stdc++.h>
using namespace std;

int getMaxLen(vector<int>& nums) {
if(nums.size()==0)return 0;

unordered_map<int,int> m;
m[0]=-1;

int ans=0;
int neg=0;
for(int i=0;i<nums.size();i++){
if(nums[i]<0)neg++;
int rem=neg%2;

if(m.find(rem)==m.end()){
    m[rem]=i;
}
else ans=max(ans,i-m[rem]);
}        
return ans;
}

int main(){

}