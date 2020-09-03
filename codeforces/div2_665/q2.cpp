#include<bits/stdc++.h>
using namespace std;

int solution(string &s) {

  
    vector<int> freq(26, 0);
    priority_queue<int> pq;
    
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
    }

    for(int i=0;i<26;i++){
        if(freq[i]>0){
        pq.push(freq[i]);
        }
    }
 
   int ans = 0;
  
    while (!pq.empty()) {
       
        int maxm = pq.top();
         pq.pop();
        if (pq.empty())return ans;
  
        if (maxm == pq.top()) {
            if (maxm > 1) {
                pq.push(maxm - 1);
            }
            ans++;
        }
    
    }
    return ans;
}