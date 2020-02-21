import java.util.*;
import java.util.HashMap; 
import java.util.Map;
class BST{
    public static void main(String[] args) {
        int [] arr={10,20,30,40,50,60,70,80};
        Node node=create(arr,0,7);
        display(node);
        // inorder(node);
        // range(node,50,80);
        HashMap<Integer,Integer> m=new HashMap<>();
         sumvertical(node,0,m);
        // diagonal(node,0,m);

        // System.out.println(widthgeneric(node,false));
        

    }

 static int widthgeneric(Node node,boolean isleft){
     if(node==null)return -1;
     int l=widthgeneric(node.left,isleft)+(isleft?1:-1);
     int r=widthgeneric(node.right,isleft)+(isleft?-1:1);

     return Math.max(l,r);
 }
    static void sumvertical(Node root,int width,HashMap<Integer,Integer> m){
        if(root==null)return ;
        if(m.containsKey(width)){
           int a= m.get(width)+root.data;
           m.put(width,a);
        }else{
            m.put(width,root.data);
        }
        sumvertical(root.left,width-1,m);
        sumvertical(root.right,width+1,m);
    }

    static void diagonal(Node root,int width,HashMap<Integer,Integer> m){
        if(root==null)return ;
        if(m.containsKey(width)){
           int a= m.get(width)+root.data;
           m.put(width,a);
        }else{
            m.put(width,root.data);
        }
        diagonal(root.left,width-1,m);
        diagonal(root.right,width,m);
    }

    static void range(Node root,int l,int r){
        if(root==null)return;
        if(l<root.data&&r<root.data)range(root.left,l,r);
       else  if(l>root.data&&r>root.data)range(root.right,l,r);
      else{  System.out.print(root.data+" ");
         range(root.left,l,r);
         range(root.right,l,r);
    }
    }
    static void inorder(Node root){
        if(root==null)return;
        inorder(root.left);
        System.out.print(root.data+" ");
        inorder(root.right);
    }

    static Node create(int[] arr,int start,int end){
        if(start>end)return null;
        int mid=(start+end)>>1;
        Node root=new Node(arr[mid],create(arr,start,mid-1),create(arr,mid+1,end));
        // root.left=create(arr,start,mid-1);
        // root.right=create(arr,mid+1,end);
        return root;
    }

  static Node minimum(Node root){
      Node temp=root;
      while(temp.left!=null){
          temp=temp.left;
      }
      return temp;
  }
   static Node remove(Node root,int data){
       if(root==null) return null;

       if(root.data<data){
           root.right=remove(root.right,data);
       }
       else if(root.data>data){
           root.left=remove(root.left,data);
       }

       else{
           if(root.left==null){
               return root.right;
           }
           else if(root.right==null){
               return root.left;
           }
           else{
               Node temp=minimum(root.right);
               root.data=temp.data;
               root.right=remove(root.right,temp.data);
           }
       }
       return root;
    
   }
    static Node adddata(Node root, int data){
        if(root==null){
            Node node=new Node(data,null,null);
            return node;
        }

        if(data<root.data){
            root.left=adddata(root.left,data);
        }
        else {
             root.right=adddata(root.right,data);
        }
        return root;
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

class element{
    boolean l=false;
    boolean sf=false;
    boolean r=false;
}
static void inorderstack(Node root){

}
}