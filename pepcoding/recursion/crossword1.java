public class crossword1 {
    public static void main(String[] args){
        System.out.println("k");
    }

    static boolean check(char[][] board,int x,int y, String word){
        if(board[x][y+word.length]!='+')return false;
       else  if(y+word.length>=board[0].length)return false;
  else{
        int k=0;
        for(int i=y;i<y+word.length;i++){
            if((board[x][i] != word.charAt(k++))&&(board[x][i] == '-')))return false;
        }
        return true;
    }
}