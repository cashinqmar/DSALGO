 #include<bits/stdc++.h>
using namespace std;

    bool isvalid(vector<vector<int>> &grid,int x,int y){
    return x>=0&&x<grid.size()&&y>=0&&y<grid[0].size();
}

vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

void dfs(vector<vector<int>> &grid,int x,int y,queue<pair<pair<int,int>,int>> &q){
grid[x][y]=2;
q.push({{x,y},0});
for(int i=0;i<4;i++){
    int newx=x+dir[i][0];
    int newy=y+dir[i][1];
    if(isvalid(grid,newx,newy)&&grid[newx][newy]==1){
          dfs(grid,newx,newy,q);
      }
    }

}
    int shortestBridge(vector<vector<int>>& grid) {
       queue<pair<pair<int,int>,int>> q;
        bool flag=false;
        for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
        if(grid[i][j]==1){
            dfs(grid,i,j,q);
            flag=true;
            break;
        }
    }
            if(flag)break;
}

for(auto i:grid){
    for(auto j:i)cout<<j<<" ";
    cout<<"\n";
}        

while (!q.empty())
{
    pair<pair<int,int>,int> temp=q.front();q.pop();
    int x=temp.first.first;
    int y=temp.first.second;
    int dist=temp.second;

     for(int i=0;i<4;i++){
    int newx=x+dir[i][0];
    int newy=y+dir[i][1];
    if(isvalid(grid,newx,newy)){
     if(grid[newx][newy]==1)return dist;
        if(grid[newx][newy]==0){
         q.push({{newx,newy},dist+1});
         grid[newx][newy]=2;
     }
      }
    }
}
 return 0;
    
}
  int main(){

}  