#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

for(int i=0;i<matrix.size();i++){
    pq.push({matrix[i][0],i,0});
}
int count=0;
int ans;
while(count<k){
    vector<int> temp=pq.top();pq.pop();
    ans=temp[0];
    int x=temp[1];
    int y=temp[2];

    if(y+1<matrix[0].size())pq.push({matrix[x][y+1],x,y+1});

    count++;
}
return ans;
}
int main(){

}