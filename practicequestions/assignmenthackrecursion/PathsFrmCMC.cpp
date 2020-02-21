#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<vector<int>>& board, int x ,int y){
    return ((x>=0)&&(x<board.size())&&(y>=0)&&(y<board[0].size()));
}

vector< vector<int>> arr={{1,0},{0,1},{0,-1},{-1,0}};

int printpaths(vector<vector<int>>& board,vector<vector<bool>>& visited ,int  x,int y,string ans){
    if((x==board.size()/2) && (y==board[0].size()/2)){
        cout<<ans.substr(0,ans.size()-3)<<"MID"<<endl;
        return 1;
    }

    int count=0;
    for(int i=0;i<4;i++){
        int newx=x+arr[i][0]*board[x][y];
        int newy=y+arr[i][1]*board[x][y];

        if(isvalid(board,newx,newy)&&(visited[newx][newy]==false)){
            visited[newx][newy]=true;
            count+=printpaths(board,visited,newx,newy,ans+to_string(newx)+to_string(newy)+" ");
            visited[newx][newy]=false;
        }
    }
    return count;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> board(n,vector<int>(m));
    vector<vector<bool>> visited(n,vector<bool>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<n;i++){
      visited[i][0]=true;
      string ans=to_string(i)+to_string(0)+" ";
      printpaths(board,visited,i,0,ans);
      visited[i][0]=false;
    }

}
int main(){
    solve();
    return 0;
}