#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > arr={{0,1},{1,0},{0,-1},{-1,0}};
vector<string> dir={"r","d","l","u"};

bool isvalid(int x,int y,vector< vector<int>>& board){
    return (x>=0)&&(x<board.size())&&(y>=0)&&(y<board.size())&&(board[x][y]==0);
}
int floodfill(int sr,int sc,int dr,int dc, vector< vector<int>>& board,int radius ,string ans){
    if(sr==dr&&sc==dc){
       cout<<ans<<endl;
        int l=ans.size();
        return 1;
    }
    int count=0;
    board[sr][sc]=1;
    for(int j=1;j<=radius;j++){
        for(int i=0;i<4;i++){
            int x=sr+arr[i][0]*j;
            int y=sc+arr[i][1]*j;

            if(isvalid(x,y,board)){
            count+=floodfill(x,y,dr,dc,board,radius,ans+dir[i]+to_string(j));
            }
        }
    }
    board[sr][sc]=0;
    return count;
}


void solve(){
    int m=3,n=3;
vector< vector<int>> arr(n,vector<int>(m,0));
cout<<floodfill(0,0,2,2,arr,2,"")<<endl;
}
int main(){
    solve();
    return 0;
}