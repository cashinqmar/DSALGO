#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
int count=0;
while(count++<t){
    vector<int> time(1441,0);
    // vector<int> start(1441);
    // vector<int> end(1441);

    int n;
    cin>>n;

    int minm=100000;
    vector<pair<pair<int,int>,int>> p;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        // start[x]=y;
        // end[y]=x;
        p.push_back({{x,y},i});

        time[x]++;
        time[y]--;
    }


    bool flag=true;
    int ctr=0;
    for(int i=0;i<1441;i++){
      if(time[i]>0){ 
          ctr+=time[i];

        //   cout<<i<<" a"<<ctr<<endl;;
        //   cout<<ctr<<" ";
      }
      if(time[i]<0){
          ctr+=time[i];
        //   cout<<i<<" a"<<ctr<<endl;
        //   cout<<ctr<<" ";
      }

       if(ctr>2){
          flag=false;
          break;
      }
    }

    if(!flag){
 cout<<"Case #"<<count<<": "<<"IMPOSSIBLE"<<"\n";
 continue;
    }

    sort(p.begin(),p.end(),[](pair<pair<int,int>,int> &a,pair<pair<int,int>,int>&b){
        if(a.first==b.first)return a.first.second<b.first.second;
        else return a.first.first<b.first.first;
        
    });

//   for(auto i:p)cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;

    string s;
    s.resize(n);

    s[p[0].second]='C';
    int prev=1;
    int start=p[0].first.first;
    int end=p[0].first.second;

    for(int i=1;i<n;i++){
        if(start<=p[i].first.first&&end>p[i].first.first){
            if(prev==1){
                s[p[i].second]='J';
                prev=0;
            }
            else{
                s[p[i].second]='C';
                prev=1;
            }
        }
        else{
            if(prev==1)s[p[i].second]='C';
            else s[p[i].second]='J';
        }
        start=p[i].first.first;
        end=p[i].first.second;
        
    }

   cout<<"Case #"<<count<<": "<<s<<"\n";
}
}