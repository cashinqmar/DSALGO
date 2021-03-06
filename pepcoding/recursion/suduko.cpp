#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>& box,int x,int y,int n){
    for(int i=0;i<9;i++){
        if(box[x][i]==n||box[i][y]==n)return false;
    }

int r=(x/3)*3;
int c=(y/3)*3;
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(box[i+r][j+c]==n)return false;
    }
}
return true;
}

int sudoku01(vector<vector<int>>& box,int idx){
 if(idx==81){
        for(vector<int>& arr : box){
            for(int ele : arr)cout<<ele<<" ";
            cout<<endl;
        }
        cout<<endl;
        return 1;
 }    
int r=idx/9;
int c=idx%9;
int count=0;
if(box[r][c]==0){
    for(int i=1;i<=9;i++){
        if(check(box,r,c,i)){
            box[r][c]=i;
            count+=sudoku01(box,idx+1);
            box[r][c]=0;
        }
    }
}
else{
    count+=sudoku01(box,idx+1);
}
return count;
}
void preprocessing(vector<vector<int>> &box,vector<int>& row,vector<int>& col,vector<vector<int>>& matrix){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(box[i][j]==0)continue;
            int mask=1<<box[i][j];
            row[i]|=mask;
            col[j]|=mask;
            matrix[i/3][j/3]|=mask;
        }
    }
}

int sudoku02(vector<vector<int>>& box,int idx,vector<int>& row,vector<int>& col,vector< vector<int>>& matrix){
    if(idx==81){
        for(vector<int>& arr : box)
        for(int ele : arr)cout<<ele<<" ";
        cout<<endl;
        return 1;
    }
    int count=0;
    int r=idx/9;
    int c=idx%9;
    if(box[r][c]==0){
        for(int val=1;val<=9;val++){
            if((row[r]&val==0)&&(col[c]&val==0)&&(matrix[r/3][c/3]&val==0)){
                int mask=1<<val;
                row[r]^=mask;
                col[c]^=mask;
                matrix[r/3][c/3]^=mask;
                count+=sudoku02(box,idx+1,row,col,matrix);
                row[r]^=mask;
                col[c]^=mask;
                matrix[r/3][c/3]^=mask;

            }
        }
    }
    else{
        count+=sudoku02(box,idx+1,row,col,matrix);
    }
    return count;
}


int main(){
    vector< vector<int>> box=   {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                {0, 8, 7, 0, 0, 0, 0, 3, 1},
                                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                {0, 0, 5, 2, 0, 6, 3, 0, 0}};
     //cout<<sudoku01(box,0)<<endl;
     vector<int> row(9,0);
     vector<int> col(9,0);
     vector<vector<int>> matrix(3,vector<int> (3,0));
     preprocessing(box,row,col,matrix);
     cout<<sudoku02(box,0,row,col,matrix);
}
