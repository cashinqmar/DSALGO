#include<bits/stdc++.h>
using namespace std;
void largest(string str,int k,string &lar){
    if(k==0)return ;
    int l=str.size();

    for(int i=0;i<l-1;i++){
        for(int j=i+1;j<l;j++){
            if(str[i]<str[j]){
                swap(str[i],str[j]);
                if(str.compare(lar)>0)lar=str;
                largest(str,k-1,lar);
                swap(str[i],str[j]);
        }
    }
}

}
solve(){
    string s;
    int k;
    cin>>s;
    cin>>k;
    string lar=s;
    largest(s,k,lar);
    cout<<lar<<endl;

}
int main(){
    solve();
    return 0;
}