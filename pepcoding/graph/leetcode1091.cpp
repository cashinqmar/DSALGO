#include<bits/stdc++.h>
using namespace std;

   bool issafe(vector<vector<int>> &grid,int x,int y){
        return (x>=0&&x<grid.size()&&y>=0&&grid[0].size()>y);
    }
    
    
 vector<vector<int>> arr={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,-1},{-1,1},{1,1}};
  
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1)return -1;
        
       queue<pair<int,int>> q;
        
        q.push({0,0});
        grid[0][0]=1;
        
        int level=1;
        while(!q.empty()){
            int t=q.size();
            while(t--){
                pair<int,int> temp=q.front();
                q.pop();
                if(temp.first==m-1&&temp.second==n-1)return level;
                for(int i=0;i<8;i++){
                    int newx=temp.first+arr[i][0];
                    int newy=temp.second+arr[i][1];
                    
                    if(issafe(grid,newx,newy)){
                        if(grid[newx][newy]==0){
                            q.push({newx,newy});
                            grid[newx][newy]=1;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }


int main(){
    vector<vector<int>> grid={{0,0,0},{1,1,0},{1,1,0}};
    cout<<shortestPathBinaryMatrix(grid)<<" ";

    for(auto i:grid){
        for(auto j:i)cout<<j<<" ";
        cout<<"\n";
    }

}