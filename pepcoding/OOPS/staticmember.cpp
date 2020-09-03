#include<bits/stdc++.h>
using namespace std;



class member{
    static int count;
    int number;
    public:
    void getcount(int a){
        number=a;
        count++;
    }
    static void  showcount(){
        cout<<count<<endl;
    }
};

int member::count;

int main(){
    member a,b,c;
    member::showcount();
  
    a.getcount(10);
    b.getcount(10);
    c.getcount(10);
    member::showcount();
}

