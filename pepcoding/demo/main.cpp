#include<iostream>
using namespace std;
void inc(int n){
    if(n==0)return;
    cout<<n<<" ";
    inc(n-1);
     cout<<n<<" ";
}

string removehi(string str){
    if(str.size()==0){
       return "";
    }
    char ch=str[0];
    if(str.size()>1&&str[0]=='h'&&str[1]=='i'){
        return removehi(str.substr(2));
    }
    else {
        return ch+removehi(str.substr(1));
    }

}

string rhiwhit(string str){
    if(str.size()==0){
        return "";
    }
    char ch=str[0];
    if(str.size()>1&&str[0]=='h'&&str[1]=='i'){
        if(str.size()>2&&str[2]=='t'){
            return "hit"+rhiwhit(str.substr(3));
        }
        else return rhiwhit(str.substr(2));
    }
    else{
        return ch+rhiwhit(str.substr(1));
    }
}

void removedup(string ques,string ans){
    if(ques.size()==0){
        cout<<ans;
    }
    removedup(ques.substr(1),ans);
    char ch=ques[0];
    int flag=0;
    for(int i=0;i<ans.size();i++){
        if(ch==ans[i]){
            flag=1;
        }
    }
    if(!flag){
        ans=ans+ch;
    }


}

void solve(){
//inc(10);
//cout<<removehi("hifhdihi");
//cout<<rhiwhit("hithigdh");
string ans;
removedup("abcbccb",ans);
}

int main(){
   solve();
    return 0;
}