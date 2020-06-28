#include<bits/stdc++.h>
using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {

 auto comp=[](vector<int>& a,vector<int> &b){
       int num1=a[0];
       int deno1=a[1];
       int num2=b[0];
       int deno2=b[1];
     
       return num1*deno2>num2*deno1;
};
    priority_queue<vector<int>,vector<vector<int>>,decltype(comp)> pq(comp);

    for(int j=A.size()-1;j>0;j--)
        pq.push({A[0],A[j],0,j});
     


    vector<int> ans(2);
    int count=0;
    while(count<K){
    vector<int> temp=pq.top();pq.pop();
    count++;
    ans={temp[0],temp[1]};
    // cout<<ans[0]<<" "<<ans[1]<<" ,";
    int i=temp[2]+1;
    int j=temp[3];

        if(i<j)
        pq.push({A[i],A[j],i,j});
    
    }

    return ans;
}
int main(){
vector<int> A={1,7,23,29,47};
int k=8;
kthSmallestPrimeFraction(A,k);

}