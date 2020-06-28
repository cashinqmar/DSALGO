#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        unordered_map<char,int> m;
        for(int i=0;i<str.size();i++){
            m[str[i]]++;
        }

        unordered_set<int> check;
        for(auto i:m){
            check.insert(i.second);
        }

        if(check.size()>2){
            cout<<0<<"\n";
        }
        else if(check.size()==1){
            cout<<1<<"\n";
            
        }
        else if(check.size()==2){
            // cout<<"inside<< ";

              vector<int> arr;
            for(auto i:check){
            arr.push_back(i);
            }
            sort(arr.begin(),arr.end());
            // cout<<arr[0]<<" "<<arr[1]<<" ";

        bool flag=false;
         if(arr[0]==1){
                 int a=arr[0];
                    int count=0;
                    for(auto i:m){
                        if(i.second==a){
                            count++;                        }
                    }
                    if(count==1){
                        flag=true;
                    }
                  
            }
              if(arr[1]==arr[0]+1){
                    int a=arr[1];
                    int count=0;
                    for(auto i:m){
                        if(i.second==a){
                            count++;                        }
                    }
                    if(count==1){
                       flag=true;
                    }
                   
            }
            if(flag==true)cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else{
            cout<<"1"<<"\n";
        }
    }
}