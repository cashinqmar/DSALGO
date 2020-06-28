#include<bits/stdc++.h>
using namespace std;
  
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
int count=0;

priority_queue<int> pq;
int k=0;

while(k<stations.size()){
    if(startFuel>=stations[k][0]){
        pq.push(stations[k][1]);
        k++;
    }
    else{
           if(pq.size()==0)return -1;
        while(pq.size()!=0&&startFuel<stations[k][0]){
            startFuel+=pq.top();
            pq.pop();count++;
        }
    }
}

while((startFuel<target)&&(pq.size()!=0)){
    startFuel+=pq.top();
    pq.pop();
    count++;
}
if(startFuel>=target)return count;
return -1;
}


int main(){

}