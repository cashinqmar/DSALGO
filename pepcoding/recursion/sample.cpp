#include<bits/stdc++.h>
using namespace std;
#define vii vector< vector<int>>
bool isSafeToPlaceNumber(vii &boxe, int r, int c, int val)
{

    for (int i = 0; i < 9; i++)
        if (boxe[i][c] == val)
            return false;

    for (int j = 0; j < 9; j++)
        if (boxe[r][j] == val)
            return false;

    int nr = (r / 3) * 3;
    int nc = (c / 3) * 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (boxe[nr + i][nc + j] == val)
                return false;

    return true;
}
int Sudoku_01(vii &boxe, int vidx)
{
    if (vidx == 81)
    {
        for(vector<int>& arr : boxe){
            for(int ele : arr)cout<<ele<<" ";
            cout<<endl;
        }
        cout<<endl;
        return 1;
    }

    int count = 0;
    int r = vidx / 9;
    int c = vidx % 9;
    if (boxe[r][c] == 0)
    {
        for (int val = 1; val <= 9; val++)
        {
            if (isSafeToPlaceNumber(boxe, r, c, val))
            {
                boxe[r][c] = val;
                count += Sudoku_01(boxe, vidx + 1);
                boxe[r][c] = 0;
            }
        }
    }
    else
    {
        count += Sudoku_01(boxe, vidx + 1);
    }

    return count;
}

int main(){
    vector< vector<int>> box=   {{3, 0, 0, 5, 0, 8, 4, 0, 0},
                                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                                {0, 8, 0, 0, 0, 0, 0, 3, 1},
                                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                                {0, 0, 5, 2, 0, 6, 3, 0, 0}};
     cout<<Sudoku_01(box,0)<<endl;
}