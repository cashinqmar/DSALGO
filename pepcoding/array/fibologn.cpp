#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> multiplication(vector<vector<int>> &a,vector<vector<int>> &b){
      vector<vector<int>> c(2,vector<int>(2,0));
        c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
        c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
        c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[0][1];
        c[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];
        
        return c;
    }
    
    vector<vector<int>> helper(vector<vector<int>> &m,int n){
        if(n==1)return m;
         vector<vector<int>> rec=helper(m,n/2);
          vector<vector<int>> ans= multiplication(rec,rec);
          if(n%2==1)return multiplication(ans,m);
          else return ans;
    }
    
    int fib(int n) {
    vector<vector<int>> m={{1,1},{1,0}};
   vector<vector<int>> ans=helper(m,n);
   return ans[0][1];
    }
int main(){
    int n=3;
    cout<<fib(n);
}