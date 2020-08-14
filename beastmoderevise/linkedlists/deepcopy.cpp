#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    Node* temp=head;

    while(temp){
        Node *newnode=new Node(temp->val);
        newnode->next=temp->next;
        newnode->random=temp->random;
        Node* temp2=temp->next;
        temp->next=newnode;
        newnode->next=temp2;
        temp=temp2;
    }
    temp=head;

    while(temp){
        if(temp->random!=NULL){
            temp->next->random=temp->random->next;
        }
    }

         Node* h1= head;
        Node* ans=h1->next;
        Node* h2=ans;
        while(h1)
        {
            h1->next=h1->next->next;
            if(h2->next)
            h2->next=h2->next->next;
            h1=h1->next;
            h2=h2->next;
        }
        return ans;
}


int main(){

}