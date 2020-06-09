#include<bits/stdc++.h>
using namespace std;


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> s;
    for(int i=0;i<wordList.size();i++){
       s.insert(wordList[i]);
    }

    queue<pair<string,int>> q;
    q.push({beginWord,2});
    s.erase(beginWord);
    while(!q.empty()){
        pair<string,int> temp=q.front();q.pop();
        string word=temp.first;
        int dist=temp.second;

        for(int i=0;i<word.size();i++){
            char ch=word[i];
            for(int k=0;k<26;k++){
                char ch1='a'+k;
                if(ch==ch1)continue;
                word[i]=ch1;      
                if(s.find(word)!=s.end()){
                   if(word==endWord)return dist;
                    q.push({word,dist+1});
                    s.erase(word);
                }
            }
            word[i]=ch;
        }
    }
    return 0;
}
int main(){
char ch='a';
char ch1='a'+1;
cout<<ch1;
}