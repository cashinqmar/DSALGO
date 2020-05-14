#include<bits/stdc++.h>
using namespace std;

 class Node
    {
    public:
        int data = 0;
        Node* next = nullptr;

        Node(int data)
        {
            this->data = data;
        }
    };

class linkedlist
{

private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

public:
    //generalUtil.======================================

    int size()
    {
        return this->size;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    Node *getNodeAt(int idx)
    {
    }

    //add.============================================

private:
    void addFirstNode(Node *node)
    {
    }

    void addLastNode(Node *node)
    {
    }

    void addAtNode(Node *node, int idx)
    {
    }

public:
    void addFirst(int data)
    {
        Node *node = new Node(data);
        addFirstNode(node);
    }

    void addLast(int data)
    {
        Node *node = new Node(data);
        addLastNode(node);
    }

    void addAt(int data, int idx)
    {
        Node *node = new Node(data);
        addAtNode(node, idx);
    }

    //get.===============================================

    //remove.=============================================
};

void solve(){
    linkedlist ll;
    ll;
}

int main()
{    solve();
    return 0;
}