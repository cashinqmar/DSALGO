import java.util.*;
import java.util.HashMap;

class BTtree{
   public static void main(String[] args) {
    int[] arr = { 1,2,100,-1,-1,99,-1,-1,0,1,-1,-1,5,-1,-1};
    Node root = create(arr);
   display(root);
    // ArrayList<Node> ans= roottonodepath(root, 100);
    // for(Node ele : ans){
    //     System.out.print(ele.data+" ");
    // }
    // leafnodesum(root);

    // HashMap<Integer,Integer> m=new HashMap<>();
    // m.put(0,1);
    
    // System.out.println(pathSum_III(root, 0, 8, m));

    
    nodetonode(root);
    System.out.println(ans);

   }

   static int ans=(int)-1e8;

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

   public static int pathSum_III(Node node, int prefixSum, int tar, HashMap<Integer, Integer> map) {
    if (node == null)
        return 0;

    prefixSum += node.data;
    int count = map.getOrDefault(prefixSum - tar, 0);

    map.put(prefixSum, map.getOrDefault(prefixSum, 0) + 1);

    count += pathSum_III(node.left, prefixSum, tar, map);
    count += pathSum_III(node.right, prefixSum, tar, map);

    if (map.get(prefixSum) == 1) {
        map.remove(prefixSum);
    } else {
        map.put(prefixSum, map.get(prefixSum) - 1);
    }
    return count;
}
//    static boolean find(Node root, int data){
//        if(root==null)return false;
//        if(root.data==data)return true;
//        boolean res=false;
//        res|=find(root.left,data);
//        res|=find(root.right,data);
//        return res;
//    }

//    static ArrayList<Node> roottonodepath(Node root,int data){
//        if(root==null){
//            return null;
//        }
//        if(root.data==data){
//         ArrayList<Node> base=new ArrayList<Node>();
//         base.add(root);
//         return base;
//        }
//        ArrayList<Node>  left=roottonodepath(root.left, data);
//        if(left!=null){
//            left.add(root);
//            return left;
//        }

//        ArrayList<Node> right=roottonodepath(root.right, data);
//        if(right!=null){
//         right.add(root);
//         return right;
//     }
//     return null;
// }
// public static class BSTpair{
//     boolean isBST=true;
//     int count=0;
//     int lBSTsize=0;
//     Node LBST=null;
//     int max=(int)1e8;
//     int min=(int) -1e8;
// }

// static BSTpair sol(Node root){
//   if(root==null){
//       BSTpair ans= new BSTpair();
//       return ans;
//   }
//   BSTpair left=sol(root.left);
//   BSTpair right=sol(root.right);

//   BSTpair myans= new  BSTpair(); 
//   myans.count=left.count+right.count;
//   if(left.isBST&&right.isBST&&(root.data>left.max&&root.data<=right.min)){
//     myans.count++;
//     myans.lBSTsize=left.lBSTsize + right.lBSTsize;
//     myans.LBST=root;
//   }
//   else{
//       myans.isBST=false;
//       if(left.lBSTsize>right.lBSTsize){
//           myans.lBSTsize=left.lBSTsize;
//           myans.LBST=left.LBST;
//       }
//       else{
//           myans.lBSTsize=right.lBSTsize;
//           myans.LBST=right.LBST;
//       }
//   }
//   myans.max=Math.max(Math.max(left.max,right.max),root.data);
//   myans.min=Math.min(Math.min(left.min,right.min),root.data);

//   return myans;
// }


// static int leaftoleaf(Node node){
//     if(node==null){
//         return 0;
//     }
//     int left=leaftoleaf(node.left);
//     int right=leaftoleaf(node.right);
//     if(node.left!=null && node.right!=null){
//       ans=Math.max(ans,left+right+node.data);
//       return Math.max(left,right)+node.data;
//     }

//     if(node.left==null){
//         return right+node.data;
//     }
//     else return left+node.data;
// }
// public static class variable{
//     int maxsum=0;
//     int pathmax=0;
// };

// static variable nodetonode(Node root){
//     if(root==null){
//         return new variable();
//     }
//     variable left=nodetonode(root.left);
//     variable right=nodetonode(root.right);
//     variable myans=new variable();
//     ans=Math.max(Math.max(Math.max(left.maxsum,right.maxsum),Math.max(left.pathmax+root.data,right.pathmax+root.data)),Math.max(ans,left.pathmax+right.pathmax+root.data));


//     myans.maxsum=ans;
//     myans.pathmax=Math.max(left.pathmax,right.pathmax)+root.data;

// return myans;
// }

static int  nodetonode(Node root){
    if(root==null){
        return 0;
    }
    int left=Math.max(0,nodetonode(root.left));
    int  right=Math.max(0,nodetonode(root.right));
    ans=Math.max(ans,left+right+root.data);
    return Math.max(left,right)+root.data;
}



}
