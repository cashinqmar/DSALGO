#include<iostream>
#include<vector>
using namespace std;

bool isvalid(vector<vector<bool>>& board, int x ,int y){
    return ((x>=0)&&(x<board.size())&&(y>=0)&&(y<board.size()));
}

vector< vector<int>> arr={{0,1},{1,0},{0,-1},{-1,0}};


bool ratinamaze(vector<vector<bool>>& board,int x,int y,int idx,int moves){
    if((x==board.size()-1)&&(y==board.size()-1)&&(idx<=moves)){
        return true;
    }

    bool res=false;
    for(int i=0;i<4;i++){
     int newx=x+arr[i][0];
     int newy=y+arr[i][1];
     if(isvalid(board,newx,newy)&&(board[newx][newy]==false)){
         board[newx][newy]=true;
         res|=ratinamaze(board,newx,newy,idx+1,moves);
         if(res)break;
        board[newx][newy]=false;
     }
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<bool>> board(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            if(x==0)board[i][j]=true;
        }
    }
    int moves;
    cin>>moves;
    board[0][0]=true;
    if(ratinamaze(board,0,0,0,moves))cout<<"true";
    else cout<<"false";
}

int main(){
    solve();
    return 0;
}