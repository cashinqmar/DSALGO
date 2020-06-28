#include<bits/stdc++.h>
using  namespace std;

int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            if(!visited[i][0]){
                pq.push({heightMap[i][0],i,0});
                visited[i][0]=true;
            }
            if(!visited[i][m-1]){
                pq.push({heightMap[i][m-1],i,m-1});
                visited[i][m-1]=true;
            }
        }

        for(int i=0;i<m;i++){
              if(!visited[0][i]){
                pq.push({heightMap[0][i],0,i});
                visited[0][i]=true;
            }
            if(!visited[n-1][i]){
                pq.push({heightMap[n-1][i],n-1,i});
                visited[n-1][i]=true;
            }
        }

    int ans=0;

    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

    while(!pq.empty()){
        vector<int> temp=pq.top();pq.pop();

        int x=temp[1];
        int y=temp[2];

        int water=temp[0];

        for(int i=0;i<4;i++){
            int newx=x+dir[i][0];
            int newy=y+dir[i][1];

            if(newx<0||newx>=n||newy<0||newy>=m)continue;
            if(visited[newx][newy])continue;

            if(heightMap[newx][newy]>=water){
                visited[newx][newy]=true;
                pq.push({heightMap[newx][newy],newx,newy});
            }
            else{
                ans+=water-heightMap[newx][newy];
                visited[newx][newy]=true;
                pq.push({water,newx,newy});
            }
        }
    }
    return ans;
}


int main(){

}