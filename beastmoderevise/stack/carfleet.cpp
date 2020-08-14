#include<bits/stdc++.h>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>> arr(position.size());

        for(int i=0;i<position.size();i++){
            arr[i].first=position[i];
            arr[i].second=(float)(target-position[i])/(float)speed[i];
        }

        sort(arr.begin(),arr.end(),[](pair<int,float>&a,pair<int,float>&b){ return a.first>b.first;});
        int ans=0;
        float time=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i].second>time){
                ans++;
                time=arr[i].second;
            }
        }
        
return ans;
}
int main(){

}