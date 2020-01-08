#include<bits/stdc++.h>
using namespace std;

int equiset(vector<int>& arr,int sum1,int sum2,string s1,string s2,int idx){
    if(idx==arr.size()){
        if(sum1==sum2){
            cout<<s1.substr(0,s1.size()-1)<<" "<<" = "<<s2.substr(0,s2.size()-1) <<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    count+=equiset(arr,sum1+arr[idx],sum2,s1+to_string(arr[idx])+"+",s2,idx+1);
    count+=equiset(arr,sum1,sum2+arr[idx],s1,s2+to_string(arr[idx])+"+",idx+1);

    return count;
}

int main(){
vector<int> arr={10,20,30,40,50,60,70,80};
cout<<equiset(arr,10,0,"10+","",1);
}