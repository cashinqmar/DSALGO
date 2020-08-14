#include<bits/stdc++.h>
using namespace std;


// leetcode 208--------------------------------------------------------------------
class Trie {
public:
    /** Initialize your data structure here. */
    
    class node{
        public:
        int wordcount;
        vector<node*> child;
        
          
            node(){
            wordcount=0;
            child.assign(26,NULL);
        }
    };
    node* root=NULL;
    Trie() {
        
        root=new node();
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string s) {
        node*curr=root;
        int idx;
        for(int i=0;i<s.size();i++){
             idx=s[i]-'a';
            if(curr->child[idx]==NULL)curr->child[idx]=new node();
            curr=curr->child[idx];
        }
        curr->wordcount++;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string s) {
          node*curr=root;
        int idx;
        for(int i=0;i<s.size();i++){
             idx=s[i]-'a';
            if(curr->child[idx]==NULL)return false;
            curr=curr->child[idx];
        }
     return   curr->wordcount>0;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string s) {
             node*curr=root;
        int idx;
        for(int i=0;i<s.size();i++){
             idx=s[i]-'a';
            if(curr->child[idx]==NULL)return false;
            curr=curr->child[idx];
        }
     return   true;
    }
};

int main(){

}