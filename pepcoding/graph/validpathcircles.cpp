
#include<bits/stdc++.h>
using namespace std;

bool safe(int x,int y,int m,int n){
    return x>=0&&x<m&&y>=0&&y<n;
}


vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};


bool helper( vector<vector<int>>  &matrix,int sr,int sc,int dr,int dc){
    if(sr==dr&&sc==dc){
        return true;
    }
    
   bool res=false;
    
    
    for(int i=0;i<8;i++){
        int newx=sr+dir[i][0];
        int newy=sc+dir[i][1];
        if(safe(newx,newy,dr+1,dc+1)){
            if(matrix[newx][newy]==0){
                 matrix[newx][newy]=1;
                  res=res|helper(matrix,newx,newy,dr,dc);
                  if(res)return true;
                  matrix[newx][newy]=0;
            }
      
    }
    }
    
    return res;
}
void solve(int x, int y, int n, int r, vector<int> &E, vector<int> &F) {
    
    vector<vector<int>> matrix(x+1,vector<int>(y+1,0));
 
    for(int i=0;i<n;i++){
        matrix[E[i]][F[i]]=1;
        for(int j=1;j<=r;j++){
            for(int k=0;k<8;k++){
            int newx=E[i]+dir[k][0]*j;
            int newy=F[i]+dir[k][1]*j;
            if(safe(newx,newy,x+1,y+1)){
                matrix[newx][newy]=1;
            }
        }
    }
}
bool ans=true;
if(matrix[0][0]==1||matrix[x][y]==1){
    cout<<"NO";
}

else{
    
matrix[0][0]=1;

if(helper(matrix,0,0,x,y))cout<<"YES";
else cout<<"NO";
}
}

int main(){
    int a=2;
    int b=3;
    int c=1;
    int d=1;
    a=61;b= 91;c= 6;d= 2;


    vector<int> e={6 ,53, 42, 27 ,34 ,58, 29};
    vector<int> f={6, 16, 54, 33, 40 ,30, 23};
    solve(a,b,c,d,e,f);
}
