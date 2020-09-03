#include<bits/stdc++.h>
using namespace std;


 bool issafe(vector<vector<int>>& graph,int x,int y){
    int m=graph.size();
    int n=graph[0].size();
        
        return x>=0&&y>=0&&x<m&&y<n;
    }
    
    vector<vector<int>> dir={{0,1},{0,-1},{-1,0},{1,0}};
    
    
    void helper(vector<vector<int>>& graph,int x,int y){
        
        graph[x][y]=2;
           for(int i=0;i<4;i++){
            int newx=x+dir[i][0];
            int newy=y+dir[i][1];
            if(issafe(graph,newx,newy)){
                if(graph[newx][newy]==1){
                    helper(graph,newx,newy);
                }
            }
    }
        
    }
                                  
                   
    int numIslands(vector<vector<int>>& graph) {
        
        if(graph.size()==0)return 0;
         int m=graph.size();
    int n=graph[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]==1){
                    helper(graph,i,j);
                    ans++;
                    
                }
            }
        }
        
        return ans;
    }

int minDays(vector<vector<int>>& grid) {

queue<pair<int,int>> q;
for(int i=0;i<grid.size();i++){
    for(int j=0;j<grid[0].size();i++){
        if(grid[i][j]==0){
            q.push({i,j});
        }
    }
}

if(q.size()==0)return min(grid.size(),grid[0].size());

int count=1;
while(!q.empty()){
    int t=q.size();
    while(t--){
        pair<int,int> temp=q.front();q.pop();
        int x=temp.first;
        int y=temp.second;

        for(int i=0;i<4;i++){
            int newx=x+dir[i][0];
            int newy=y+dir[i][1];

            if(issafe(grid,newx,newy)){
                q.push({newx,newy});
                grid[newx][newy]=0;
            }
        }
    }

    if(numIslands(grid)%2==0)return count;
    
    count++;

}
return 0;

}