import java.util.*;
class hamiltoniancycle{
    public static void main(String[] args) {
         Scanner input = new Scanner(System.in);
       int n = input.nextInt();
       int k = input.nextInt();

        int [][]maze =new int[n][n];
        for(int i=0;i<k;i++){
           int x,y;
           x=input.nextInt();
           y=input.nextInt();
           maze[x][y]=1;
           maze[y][x]=1;
        }
        int[] path=new int[n];
        for(int i=0;i<n;i++)path[i]=-1;
        path[0]=0;
  hamilton(maze,path,1);
    }

    static boolean issafe(int[] path,int pos,int[][] graph,int v){
        if(graph[path[pos-1]][v]!=1)return false;
        for(int i=0;i<pos;i++){
            if(path[i]==v)return false;
        }
        return true;
    }

   static boolean hamilton(int[][] graph,int[] path,int pos){
        if(pos==graph.length){
            if(graph[path[pos-1]][path[0]]==1){

                System.out.println("P:"+Arrays.toString(path));
               System.out.println("C:"+Arrays.toString(path));
                return true;
            }
            else{
                 System.out.println("P:"+Arrays.toString(path));
                 System.out.println("C:null");
               return false;
             }
            }
            boolean res=false;
            for(int v=1;v<graph.length;v++){
                if(issafe(path,pos,graph,v)){
                    path[pos]=v;
                    res|=hamilton(graph,path,pos+1);
                    path[pos]=-1;
                }
            }
            return res;
        }
    }