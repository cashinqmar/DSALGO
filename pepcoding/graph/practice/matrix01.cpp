#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
queue<pair<pair<int,int>,int>> q;
int n=matrix.size();
int m=matrix[0].size();
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(matrix[i][j]==0){
            q.push({{i,j},0});
        }
    }
}

vector<vector<int>> ans(n,vector<int>(m,0));

vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

while(!q.empty()){
    pair<pair<int,int>,int> temp=q.front();q.pop();
    int x=temp.first.first;
    int y=temp.first.second;
    int dist=temp.second;
    ans[x][y]=dist;
     for (int i = 0; i < 4; i++)
               {
                   int newx=x+dir[i][0];
                   int newy=y+dir[i][1];
                   if((newx>=0)&&(newx<matrix.size())&&(newy>=0)&&(newy<matrix[0].size())){
                       if(matrix[newx][newy]==1){
                           q.push({{newx,newy},dist+1});
                            matrix[newx][newy]=0;
                       }
                   }
               }
}
return ans;
}

int main(){

}