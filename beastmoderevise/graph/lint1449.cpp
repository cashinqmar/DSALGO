#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param richer: the richer array
     * @param quiet: the quiet array
     * @return: the answer
     */
     
    int helper(vector<vector<int>> &graph,int src,vector<int> &quiet,vector<int> &ans){
        if(ans[src]!=-1)return ans[src];
        int idx=src;
        for(auto i: graph[src]){
           if(quiet[helper(graph,src,quiet,ans)]<quiet[idx]){
               idx=helper(graph,src,quiet,ans);
           }
        }
        return ans[src]=idx;
    }
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        // Write your code here.
        
        int n=quiet.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<richer.size();i++){
            graph[richer[i][0]].push_back(richer[i][1]);
        }
        vector<int> ans(n,-1);
        
        for(int i=0;i<ans.size();i++){
            if(ans[i]==-1){
                helper(graph,i,quiet,ans);
            }
        }
        
        return ans;
    }
};