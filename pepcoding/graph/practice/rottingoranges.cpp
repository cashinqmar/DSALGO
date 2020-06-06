#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        int rot=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    rot++;
                    q.push({i,j});   
                }
                if(grid[i][j]==1){
                   fresh++;
                }
            }
        }
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        int time=0;
        int process=0;
        while(!q.empty()){
           int t=q.size();
           while(t--){
               pair<int,int> temp=q.front();q.pop(); process++;
               int x=temp.first;
               int y=temp.second;
               for (int i = 0; i < 4; i++)
               {
                   int newx=x+dir[i][0];
                   int newy=y+dir[i][1];
                   if((newx>=0)&&(newx<grid.size())&&(newy>=0)&&(newy<grid[0].size())){
                       if(grid[newx][newy]==1){
                           q.push({newx,newy});
                            grid[newx][newy]=2;
                       }
                   }
               }
               
           }
           time++;
        }

        if(rot+fresh==process)return time-1;
        else return -1;
    }

int main(){

}    