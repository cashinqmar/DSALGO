  #include<bits/stdc++.h>
  using namespace std;

  vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
        // Write your code here
        unordered_map<int,vector<int>> m;
        for(int i=0;i<B.size();i++)m[B[i]].push_back(i);
        
        vector<int> ans(A.size(),0);
        
        for(int i=0;i<A.size();i++){
            int x=A[i];
            int a=m[B[x]].size();
            int c=m[B[x]][a-1];
            m[B[x]].pop_back();
            ans[c];
        }
        return ans;
}

    int main(){

    }