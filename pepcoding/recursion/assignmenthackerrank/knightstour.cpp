#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> arr={{1,2},{2,1},{1,-2},{2,-1},{-2,-1},{-1,-2},{-2,1},{-1,2}};

bool isvalid(vector<vector<bool>>& board, int x ,int y){
    return ((x>=0)&&(x<board.size())&&(y>=0)&&(y<board.size()));
}
// bool allvisited(vector<vector<bool>>& board){
//     for(int i=0;i<board.size();i++){
//         for(int j=0;j<board.size();j++){
//             if(board[i][j]==false)return false;
//         }
//     }
//     return true;
// }
bool knightstour(vector<vector<bool>>& board,int x ,int y,int idx){
    if(idx==board.size()*board.size()){
     return true;
    }
    bool res=false;
for(int i=0;i<8;i++){
    int newx=x+arr[i][0];
    int newy=y+arr[i][1];

    if(isvalid(board,newx,newy)&&(board[newx][newy]==false)){
         board[newx][newy]=true;
     res|=knightstour(board,newx,newy,idx+1);
     if(res)break;
         board[newx][newy]=false;
    }
}
return res;
}
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<vector<bool>> board(n,vector<bool>(n,false));
    board[x][y]=true;
    if(knightstour(board,x,y,1))cout<<"true";
    else cout<<"false";
}

int main(){
solve();
return 0;
}