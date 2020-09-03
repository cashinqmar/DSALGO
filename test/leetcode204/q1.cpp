#include<bits/stdc++.h>
using namespace std;


bool similar(vector<int>&arr,vector<int> &sample,int i,int m){
    int k=i;
    int j=0;
    while(k<arr.size()){
        if(sample[j]==arr[k]){
            j++;
            k++;
        }
        else return false;
    }

    if(k<arr.size())return true;
    else false;
}

int check(vector<int> &arr,vector<int> &sample,=int m){

   int count=0;
   int k=0;
   while(k<arr.size()){
       if(similar(arr,sample,i,m)){
           count++;
           k+=m;
       }
   }

}
bool containsPattern(vector<int>& arr, int m, int k) {
        int i=0;
       while(i<arr.size()){
           vector<int> sample(m);
           int totalcount=0;
           if(i+m<arr.size()){
           for(int j=i;j<i+m;j++){
               sample[j-i]=arr[j];
           }
            totalcount+=check(arr,sample,m);
            if(totalcount==k)return true;
       }
         i++;
}
return false;

}


int main(){

}