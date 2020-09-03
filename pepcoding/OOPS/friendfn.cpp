#include<bits/stdc++.h>
using namespace std;

class complexno{
    float x,y;
    public:
    void getnum(int x,int y){
        this->x=x;
        this->y=y;
    }
    friend complexno sum(complexno a,complexno b);
    void show(){
        cout<<x<<"i+"<<y<<endl;
     }
};

complexno sum(complexno a,complexno b){
    complexno c;
    c.x=a.x+b.x;
    c.y=a.y+b.y;
    return c;

}
int main(){
    complexno a,b,c;
    a.getnum(5,6);
    b.getnum(7,8);
    a.show();
    b.show();
    c=sum(a,b);
    c.show();
}