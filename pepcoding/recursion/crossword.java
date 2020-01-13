public class crossword{
    public static void main(String[] args) {
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

String[] words = { "agra", "norway", "england", "gwalior" };
System.out.println(crossWord(board, words, 0));

    }

    public static boolean canHPword(char[][] board, int x, int y, String word) {

        for (int j = 0; j < word.length(); j++) {
            if (board[x][y + j] != '-' && board[x][y + j] != word.charAt(j)) {
                return false;
            }
        }

        return true;
    }

    public static boolean[] HPWord(char[][] board, int x, int y, String word) {
        boolean[] loc = new boolean[word.length()];
        for (int j = 0; j < word.length(); j++) {
            if (board[x][y + j] == '-') {
                loc[j] = true;
                board[x][y + j] = word.charAt(j);
            }
        }

        return loc;
    }

    public static void UnPHWord(char[][] board, int x, int y, boolean[] loc) {
        for (int j = 0; j < loc.length; j++) {
            if (loc[j]) {
                board[x][y + j] = '-';
            }
        }
    }

    public static boolean canVPword(char[][] board, int x, int y, String word) {

        for (int j = 0; j < word.length(); j++) {
            if (board[x + j][y] != '-' && board[x + j][y] != word.charAt(j)) {
                return false;
            }
        }

        return true;
    }

    public static boolean[] HVWord(char[][] board, int x, int y, String word) {
        boolean[] loc = new boolean[word.length()];
        for (int j = 0; j < word.length(); j++) {
            if (board[x + j][y] == '-') {
                loc[j] = true;
                board[x + j][y] = word.charAt(j);
            }
        }

        return loc;
    }

    public static void UnPVWord(char[][] board, int x, int y, boolean[] loc) {
        for (int j = 0; j < loc.length; j++) {
            if (loc[j]) {
                board[x + j][y] = '-';
            }
        }
    }

    public static int crossWord(char[][] board, String[] words, int idx) {

        if (idx == words.length) {
            for (int i = 0; i < board.length; i++) {
                for (int j = 0; j < board[0].length; j++) {
                    System.out.print(board[i][j] + " ");
                }
                System.out.println();
            }

            return 1;
        }

        String word = words[idx];
        int count = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == '-' || board[i][j] == word.charAt(0)) {
                    if (canHPword(board, i, j, word)) {
                        boolean[] loc = HPWord(board, i, j, word);
                        count += crossWord(board, words, idx + 1);
                        UnPHWord(board, i, j, loc);
                    }

                    if (canVPword(board, i, j, word)) {
                        boolean[] loc = HVWord(board, i, j, word);
                        count += crossWord(board, words, idx + 1);
                        UnPVWord(board, i, j, loc);
                    }
                }
            }

        }

        return count;
    }

}