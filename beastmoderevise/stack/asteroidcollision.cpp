#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
        
stack<int> st;

for(int i=0;i<asteroids.size();i++){
    if(asteroids[i]>0){
        st.push(asteroids[i]);
    }

    else {
        while(st.size()!=0&&st.top()<abs(asteroids[i])){
            st.pop();
        }

        if(st.size()>0)continue;
        else st.push(asteroids[i]);
    }
}
vector<int> ans;
while(st.size()!=0){
    ans.push_back(st.top());
    st.pop();
}
reverse(ans.begin(),ans.end());
return ans;
}
int main(){

}