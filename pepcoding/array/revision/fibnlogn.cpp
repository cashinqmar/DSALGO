#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> a,vector<vector<int>> b){
    vector<vector<int>> c(2,vector<int>(2,0));
    c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
    c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
    c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
    c[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];

    return c;

}

vector<vector<int>> helper(vector<vector<int>> &matrix,int n){
if(n==1){
return matrix;
}

if(n%2==1){
    vector<vector<int>> ans=helper(matrix,n/2);
    vector<vector<int>> ans1=multiply(ans,ans);
    return multiply(matrix,ans1);
}
else{
 vector<vector<int>> ans=helper(matrix,n/2);
    vector<vector<int>> ans1=multiply(ans,ans);
    return ans1;
}
}

int fib(int N) {
        vector<vector<int>> mat={{1,1},{1,0}};
        return helper(mat,N)[0][1];
}

int main(){

}