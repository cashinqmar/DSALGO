// Given a matrix, source and destination index and allowed paths(u,d,r,l), print all possible paths and number
// of unique possible paths.

using namespace std;
#include <iostream>
#include <vector>

vector <vector<int>> dir {{0,1},{0,-1}, {1,0}, {-1,0}};
vector <char> dirPath = {'r','l','d','u'};

void display(vector<vector<int>> &board){
    cout<<endl;
    for(int i=0;i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    
}


bool isValid(int x , int y, vector <vector<int>> &board){
    if(x>=0 && y>=0 && x<board.size() && y<board[0].size() && !board[x][y] ){
        cout<<x<<','<<y<<" is valid"<<endl;
        return true;
    }
        cout<<x<<','<<y<<" is NOT valid"<<endl;
    return false;
}

int FloodFill(vector <vector<int>> &board, int sx, int sy, int dx, int dy, string ans){
    //board vector has values 0 or 1. 1 if visited earlier that can't be traversed anymore. 
    if(sx==dx && sy==dy){
        cout<<"Hit the base case: "<<ans<<endl;
        return 1;
    }
    int count = 0;
    cout<<endl<<"Inside ("<<sx<<','<<sy<<");"   ;
    
    board[sx][sy]=1;
    // cout<<dir.size();
    display(board);
    cout<<"Path till now: "<<ans<<endl;

    for(int i = 0; i<dir.size();i++){
        int x = sx + dir[i][0];
        int y = sy + dir[i][1];

        if(isValid(x,y,board)){
            cout<<"Calling :"<<x<<','<<y<<endl;
            count += FloodFill(board, x,y,dx,dy,ans+dirPath[i]);
        }
    }

    board[sx][sy]=0;

    return count;
}

int main(){
    int n=3,m=3;
    vector <vector<int>> board(n,vector<int>(m,0));
    // cout<<"board x: "<<board.size()<<"  "<<"board y: "<<board[0].size();
    cout<<endl<<FloodFill(board, 0,0, 2,2, "start");
    return 0;
}