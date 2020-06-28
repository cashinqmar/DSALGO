#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<int> &wieghts,int D,int wt){
int count=1;

int temp=0;
for(int i;i<wieghts.size();i++){
    if(temp+wieghts[i]>wt){
        temp=0;
        count++;
    }
    temp+=wieghts[i];
}

return count<=D;
}

int shipWithinDays(vector<int>& weights, int D) {
int low=INT_MIN;
int high=0;

for(int i=0;i<weights.size();i++){
high+=weights[i];
low=max(weights[i],low);
}

int ans=-1;
while(low<=high){
    int mid=(low+high)/2;

    if(isvalid(weights,D,mid)){
        ans=mid;
        high=mid;
    }
    else{
        low=mid;
    }
}

return ans;
}


int main(){

}