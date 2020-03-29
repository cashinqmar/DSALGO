#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    
    stack<int> st1,st2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(st1.size()!=0){
            st2.push(st1.top());
            st1.pop();
        }
        int x;
        x=st2.top();
             st2.pop();
        while(st2.size()!=0){
            st1.push(st2.top());
            st2.pop();
        }
        return x;
        
    }
    
    /** Get the front element. */
    int peek() {
         while(st1.size()!=0){
            st2.push(st1.top());
            st1.pop();
        }
        int x;
        x=st2.top();
        while(st2.size()!=0){
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        
        return st1.empty();
    }
};

int main(){
    MyQueue* obj=new MyQueue();
    obj->push(10);
    obj->push(20);
    obj->push(30);
    obj->push(40);
    obj->pop();
    cout<<obj->peek()<<endl;
    obj->push(50);
    cout<<obj->peek()<<endl;
}