#include<bits/stdc++.h>
using namespace std;

void fill( vector<vector<int>> &matrix,char ch,int a,int b){

    int newi=a*3;
    int newj=b*3;
    if(ch=='/'){
    int count=newj+2;
      for(int i=newi;i<newi+3;i++){
          for(int j=newj;j<newj+3;j++){
             if(count==j){
                 matrix[i][j]=1;
             }
          }
          count--;
      }
    }
    else if(ch==' '){
       return ;
    }
    else{
        int count=newj;
      for(int i=newi;i<newi+3;i++){
          for(int j=newj;j<newj+3;j++){
             if(count==j){
                 matrix[i][j]=1;
             }
          }
          count++;
      }
    }
}

vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

void dfs(vector<vector<int>> &matrix,int x,int y){
    matrix[x][y]=1;
    for(int i=0;i<4;i++){
        int newx=dir[i][0]+x;
        int newy=dir[i][1]+y;

        if(newx>=0&&newx<matrix.size()&&newy>=0&&newy<matrix[0].size()&&matrix[newx][newy]==0){
            dfs(matrix,newx,newy);
        }
    }
}
int regionsBySlashes(vector<string>& grid) {        
        if(grid.size()==0)return 0;
        
        int n=grid.size()*3;
        int m=grid[0].size()*3;

        vector<vector<int>> matrix(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                fill(matrix,grid[i][j],i,j);
            }
        }
  int count=0;
  
   for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
              if(matrix[i][j]==0){
                  dfs(matrix,i,j);
                  count++;
              }
            }
        }
        return count;

}
int main(){
    vector<string> grid={"/\\",
  "\\/"};
  cout<<regionsBySlashes(grid);
}