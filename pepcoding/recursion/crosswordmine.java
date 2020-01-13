import java.io.PrintStream;

public class crosswordmine{
    public  static void main( String[] args) {
        char[][] board = { { '+', '-', '+', '+', '+', '+', '+', '+', '+', '+' },
        { '+', '-', '+', '+', '+', '+', '+', '+', '+', '+' },
        { '+', '-', '-', '-', '-', '-', '-', '-', '+', '+' },
        { '+', '-', '+', '+', '+', '+', '+', '+', '+', '+' },
        { '+', '-', '+', '+', '+', '+', '+', '+', '+', '+' },
        { '+', '-', '-', '-', '-', '-', '-', '+', '+', '+' },
        { '+', '-', '+', '+', '+', '-', '+', '+', '+', '+' },
        { '+', '+', '+', '+', '+', '-', '+', '+', '+', '+' },
        { '+', '+', '+', '+', '+', '-', '+', '+', '+', '+' },
        { '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' } };


  String[] words={"agra", "norway", "england", "gwalior" };
  System.out.println(crossword(board, 0, words));
    }

    static boolean canHP(char [][] board, int x,int y, String word){
        if(y+word.length()>board[0].length)return false;
        if((y-1>=0)&&(board[x][y-1]!='+'))return false;                               
        if((y+word.length()<board[0].length) && board[x][y+word.length()]!='+') return false;

        for(int i=0;i<word.length();i++){
            if(board[x][y+i]!='-' && board[x][y+i]!=word.charAt(i))return false;
        }
        return true;
        
    }

    static boolean[] placeH(char [][] board, int x, int y, String word){
        boolean [] loc=new boolean [word.length()];

        for(int i=0;i<word.length();i++){
            if(board[x][y+i]=='-'){
                loc[i]=true;
                board[x][y+i]=word.charAt(i);
            }
        }
     return loc;
    }

    static void unplaceH(char[][] board, int x, int y , boolean[] loc){
        for(int i=0;i<loc.length;i++){
            if(loc[i]){
                board[x][y+i]='-';
            }
        }
    }

    static boolean canVP(char [][] board, int x,int y, String word){
        if(x+word.length()>board.length)return false;
        if((x-1>=0)&&(board[x-1][y]!='+'))return false;                               
        if((x+word.length()<board.length) && board[x+word.length()][y]!='+') return false;

        for(int i=0;i<word.length();i++){
            if(board[x+i][y]!='-' && board[i+x][y]!=word.charAt(i))return false;
        }
        return true;
        
    }

    static boolean[] placeV(char [][] board, int x, int y, String word){
        boolean [] loc=new boolean [word.length()];

        for(int i=0;i<word.length();i++){
            if(board[x+i][y]=='-'){
                loc[i]=true;
                board[x+i][y]=word.charAt(i);
            }
        }
     return loc;
    }

    static void unplaceV(char[][] board, int x, int y , boolean[] loc){
        for(int i=0;i<loc.length;i++){
            if(loc[i]){
                board[x+i][y]='-';
            }
        }
    }

    static int crossword(char[][] board, int idx, String [] words){
        if(words.length==idx){
            for(int i=0;i<board.length;i++){
                for(int j=0;j<board[0].length;j++){
                    System.out.print(board[i][j]+" ");                
                }
                System.out.println();
            }
            return 1;
        }
        int count =0;
        String word=words[idx];

        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
               if(board[i][j]=='-'|| board[i][j]==word.charAt(0)){
                   if(canHP(board, i, j, word)){
                      boolean[] loc=placeH(board, i, j, word);
                      count+=crossword(board, idx+1, words);
                      unplaceH(board, i, j, loc);
                   }
                   if(canVP(board, i, j, word)){
                    boolean[] loc=placeV(board, i, j, word);
                    count+=crossword(board, idx+1, words);
                    unplaceV(board, i, j, loc);
                 }
               }
            }
        }
        return count;
    }
}