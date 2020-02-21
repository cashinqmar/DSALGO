#include<iostream>
#include<vector>
using namespace std;
   bool canHPword(vector<vector<char>>& board, int x, int y, string word){
        if(y+word.length()>board[0].size())return false;
        if((y-1>=0)&&(board[x][y-1]!='+'))return false;                               
        if((y+word.length()<board[0].size()) && board[x][y+word.length()]!='+') return false;

        for(int i=0;i<word.length();i++){
            if(board[x][y+i]!='-' && board[x][y+i]!=word[i])return false;
        }
        return true;
        
    }



    vector<bool> HPWord(vector<vector<char>>& board, int x, int y, string word) {
        vector<bool> loc(word.length());
        for (int j = 0; j < word.length(); j++) {
            if (board[x][y + j] == '-') {
                loc[j] = true;
                board[x][y + j] = word[j];
            }
        }

        return loc;
    }

    void UnPHWord(vector<vector<char>> &board, int x, int y, vector<bool>& loc) {
        for (int j = 0; j < loc.size(); j++) {
            if (loc[j]) {
                board[x][y + j] = '-';
            }
        }
    }

     bool canVPword(vector<vector<char>>& board, int x, int y, string word){
        if(x+word.length()>board.size())return false;
        if((x-1>=0)&&(board[x-1][y]!='+'))return false;                               
        if((x+word.size()<board.size() && board[x+word.size()][y]!='+')) return false;

        for(int i=0;i<word.size(();i++){
            if(board[x+i][y]!='-' && board[i+x][y]!=word[i])return false;
        }
        return true;
        
    }

     vector<bool> HVWord(vector<vector<char>>& board, int x, int y, string word) {
        vector<bool> loc(word.length());
        for (int j = 0; j < word.size(); j++) {
            if (board[x + j][y] == '-') {
                loc[j] = true;
                board[x + j][y] = word[j];
            }
        }

        return loc;
    }

    void UnPVWord(vector<vector<char>>& board, int x, int y, vector<bool> &loc) {
        for (int j = 0; j < loc.size(); j++) {
            if (loc[j]) {
                board[x + j][y] = '-';
            }
        }
    }

     int crossWord(vector<vector<char>>& board, vector<string>& words, int idx) {

        if (idx == words.size()) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    cout<<board[i][j]<< " ";
                }
                cout<<endl;
            }

            return 1;
        }

        string word = words[idx];
        int count = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '-' || board[i][j] == word[0]) {
                    if (canHPword(board, i, j, word)) {
                        vector<bool> loc = HPWord(board, i, j, word);
                        count += crossWord(board, words, idx + 1);
                        UnPHWord(board, i, j, loc);
                    }

                    if (canVPword(board, i, j, word)) {
                         vector<bool> loc= HVWord(board, i, j, word);
                        count += crossWord(board, words, idx + 1);
                        UnPVWord(board, i, j, loc);
                    }
                }
            }

        }

        return count;
    }
void solve(){
    vector<vector<char>> board(10,vector<char>(10));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>board[i][j];
        }
    }
    string str1;
    cin>>str1;

    string str;
    vector<string> dictionary;
    for(int i=0;i<str1.size();i++){
        char ch=str1[i];
        if(ch==';'){
          dictionary.push_back(str);
          str="";
        }
       else  if(ch=='\0'){
           break;
       }
        else{
            str+=ch;
        }
        
    }
     dictionary.push_back(str);
    crossWord(board,dictionary,0);

}
int main(){
    solve();
    return 0;
}