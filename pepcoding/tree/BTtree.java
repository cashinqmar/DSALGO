import java.util.ArrayList;

class BTtree{
   public static void main(String[] args) {
    int[] arr = { 10, 20, 30, -1, -1, 40, -1, -1, 50, 60, 80, -1, -1, -1, 70, 90, -1, 100, -1, -1, -1 };
    Node root = create(arr);
   // display(root);
    ArrayList<Node> ans= roottonodepath(root, 100);
    for(Node ele : ans){
        System.out.print(ele.data+" ");
    }
   }
 
   public static class Node{
       int data=0;
       Node left=null;
       Node right=null;

       Node(int data,Node left,Node right){
           this.data=data;
           this.left=left;
           this.right=right;
       }
   }
   static int idx=0;
   public static Node create(int[] arr){
       if(idx==arr.length || arr[idx]==-1){
           idx++;
           return null;
       }

       Node nnode= new Node(arr[idx],null,null);
       idx++;
       nnode.left=create(arr);
       nnode.right=create(arr);
       return nnode;
   }

   public static void display(Node root){
       if(root==null){
           return ;
       }
       String str ="";
       str+=(root.left==null)?".":root.left.data;
       str+="-> "+root.data +" <-";
       str+=(root.right==null)?".":root.right.data;
       System.out.println(str);
       display(root.left);
       display(root.right);

   }

   static boolean find(Node root, int data){
       if(root==null)return false;
       if(root.data==data)return true;
       boolean res=false;
       res|=find(root.left,data);
       res|=find(root.right,data);
       return res;
   }

   static ArrayList<Node> roottonodepath(Node root,int data){
       if(root==null){
           return null;
       }
       if(root.data==data){
        ArrayList<Node> base=new ArrayList<Node>();
        base.add(root);
        return base;
       }
       ArrayList<Node>  left=roottonodepath(root.left, data);
       if(left!=null){
           left.add(root);
           return left;
       }

       ArrayList<Node> right=roottonodepath(root.right, data);
       if(right!=null){
        right.add(root);
        return right;
    }
    return null;
}
}