#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

   vector<vector<int>> graph(numCourses);
   vector<int> incoming(numCourses,0);
   for(int i=0;i<prerequisites.size();i++){
       graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
       incoming[prerequisites[i][0]]++;
   }    

   queue<int> q;
   for(int i=0;i<incoming.size();i++){
       if(incoming[i]==0)q.push(i);
   }

vector<int> ans;
   while(!q.empty()){
       int temp=q.front();q.pop();
       ans.push_back(temp);

       for(auto i:graph[temp]){
           if(--incoming[i]==0){
               q.push(i);
           }
       }
     }

     if(ans.size()==numCourses)return ans;
     return {};
    
}

int main(){

}