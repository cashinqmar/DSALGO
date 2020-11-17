#include<bits/stdc++.h>
using namespace std;

class class_2;

class class_1{
    int data;
    public:
    void fill(int data){
        this->data=data;
    }
    void display(){
        cout<<data<<"\n";
    }
    friend void exchange(class_1 &,class_2 &);
};

class class_2{
    int data;
    public:
    void fill(int data){
        this->data=data;
    }
    void display(){
        cout<<data<<"\n";
    }
    friend void exchange(class_1 &,class_2 &);
};

void exchange(class_1 &a,class_2 &b){
    int temp=a.data;
    a.data=b.data;
    b.data=temp;
}

int main(){
class_1 a;
class_2 b;
a.fill(5);
b.fill(7);

a.display();
b.display();

exchange(a,b);

a.display();
b.display();

}