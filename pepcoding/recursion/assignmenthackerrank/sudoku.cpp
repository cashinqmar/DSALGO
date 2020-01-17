#include<iostream>
#include<vector>
using namespace std;
int sudoku(vector<vector<int>>& board,int idx,vector<int>& row,vector<int>& col,vector<vector<int>> matrix){
    if(idx==81){
        for(vector<int>& arr: board){
            for(int ele:arr){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
        return 1;
    }
    int count=0;
    int x=idx/9;
    int y=idx%9;
    if(board[x][y]==0){
    for(int i=1;i<=9;i++){
        int mask=1<<i;

        if(((row[x]&mask)==0)&&((col[y]&mask)==0)&&((matrix[x/3][y/3]&mask)==0)) {
            board[x][y]=i;
            row[x]^=mask;
            col[y]^=mask;
            matrix[x/3][y/3]^=mask;
            count+=sudoku(board,idx+1,row,col,matrix);
            board[x][y]=0;
            row[x]^=mask;
            col[y]^=mask;
            matrix[x/3][y/3]^=mask;
        }       
    }
}
else {
    count+=sudoku(board,idx+1,row,col,matrix);
}
return count;
}

void populate(vector<vector<int>>& board,vector<int> &row,vector<int> &col,vector<vector<int>>& matrix){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]!=0){
             int mask=1<<board[i][j];
             row[i]|=mask;
             col[j]|=mask;
             matrix[i/3][j/3]|=mask;
        }
        }
        }
}
void solve(){
    vector<vector<int>> board(9,(vector<int>(9)));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
         int x;
         cin>>x;
         board[i][j]=x;
        }
    }
    vector<int> row(9,0);
    vector<int> col(9,0);
    vector<vector<int> > matrix(3,vector<int>(3,0));
    populate(board,row,col,matrix);
    sudoku(board,0,row,col,matrix);
}
int main(){
    solve();
    return 0;
}