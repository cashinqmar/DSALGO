#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

priority_queue<pair<float,int>,vector<pair<float,int>>,greater<pair<float,int>>> pq;

for(int i=0;i<points.size();i++){
pair<float,int> temp={sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]),i};
pq.push(temp);
if(pq.size()>K)pq.pop();
}

vector<vector<int>> ans;
while(pq.size()!=0){
    ans.push_back(points[pq.top().second]);
    pq.pop();
}
return ans;
}
int main(){

}