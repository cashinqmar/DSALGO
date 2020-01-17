#include<iostream>
#include<vector>
using namespace std;
bool isvalid(vector<vector<bool>>& board, int x ,int y){
    return ((x>=0)&&(x<board.size())&&(y>=0)&&(y<board.size()));
}

vector< vector<int>> arr={{0,1},{1,0},{0,-1},{-1,0}};



int lroute(vector<vector<bool>>& board,int x,int y,int idx){
    if((x==board.size()-1)&&(y==board.size()-1)){
        int temp=idx;
        idx=0;
        return temp;
    }

    int longest=-1e8;

    for(int i=0;i<4;i++){
     int newx=x+arr[i][0];
     int newy=y+arr[i][1];
     if(isvalid(board,newx,newy)&&(board[newx][newy]==false)){
         board[newx][newy]=true;
         longest=max(longest,lroute(board,newx,newy,idx+1));
        board[newx][newy]=false;
     }
    }
    return longest;
}
void solve(){
   int n;
   cin>>n;
   vector<vector<bool> > board(n,vector<bool>(n,false));
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           int x;
           cin>>x;
           if(x==0)board[i][j]=true;
       }
   }
   board[0][0]=true;
  cout<< lroute(board,0,0,0);
}
int main(){
    solve();
    return 0;
}