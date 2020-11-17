#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<long long > arr(n);
    for(long long  i=0;i<n;i++){
        cin>>arr[i];
    }
    
    priority_queue<long long > formin;
    priority_queue<long long ,vector<long long >,greater<long long >> formax;

    for(long long  i=0;i<n;i++){
        formin.push(arr[i]);
        formax.push(arr[i]);

        if(formin.size()>4)formin.pop();
        if(formax.size()>5)formax.pop();
    }

    long long  pos1,pos2,pos3,pos4,pos5;
    long long  neg1,neg2,neg3,neg4;

    pos1=formax.top();formax.pop();
    pos2=formax.top();formax.pop();
    pos3=formax.top();formax.pop();
    pos4=formax.top();formax.pop();
    pos5=formax.top();formax.pop();

    neg1=formin.top();formin.pop();
    neg2=formin.top();formin.pop();
    neg3=formin.top();formin.pop();
    neg4=formin.top();formin.pop(); 


    long long  case1,case2,case3;

    case1=pos1*pos2*pos3*pos4*pos5;
    case2=(neg1*neg2*neg3*neg4)*pos5;
    case3=(neg3*neg4)*pos3*pos4*pos5;
    long long  ans=max(case1,max(case2,case3));
    cout<<ans<<"\n";

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}