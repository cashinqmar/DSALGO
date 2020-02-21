import java.util.Scanner;

class findanypath {
    public static void main(String[] args) {
        int sr,sc,dr,dc;
        Scanner input = new Scanner(System.in);
        sr = input.nextInt();
        sc = input.nextInt();
        dr = input.nextInt();
        dc = input.nextInt();
        
        int m,n;
        m = input.nextInt();
        n = input.nextInt();
        int [][]maze =new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maze[i][j] = input.nextInt();
            }
        }
       
        int [][] arr={{1,0},{0,-1},{-1,0},{0,1}};
        char [] symbol={'D','L','T','R'};

    floodfill(sr, sc, maze, "", dr, dc, arr, symbol);
        
    }
    
    
   static boolean isvalid(int[][] maze, int x,int y){
        return ((x>=0)&&(x<maze.length)&&(y>=0)&&(y<maze[0].length));
    }
  public static boolean floodfill(int sr, int sc, int[][] maze, String psf,int dr,int dc,int [][] arr,char[] symbol) {
      if(sr==dr&&sc==dc){
          System.out.println(psf);
          return true;
      }
      boolean res=false;
     
      for(int i=0;i<4;i++){
          int newx=sr+arr[i][0];
          int newy=sc+arr[i][1];
          if(isvalid(maze,newx,newy)&&(maze[newx][newy]==1)){
              maze[newx][newy]=0;
              res=res|| floodfill(newx,newy,maze,psf+symbol[i],dr,dc,arr,symbol);
               if(res)break;
              maze[newx][newy]=1;
          }
      }
      return res;
  }
    
}