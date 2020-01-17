import java.util.ArrayList;

class BSTtree{
    public static void main(String[] args) {
        
    }

    public static class BSTpair{
      boolean isBST=true;
      int count=0;
      int lBSTsize=0;
      Node lBST=null;
      int max=(int)1e8;
      int min=(int) -1e8;
}

static BSTpair sol(Node root){
    if(root==null){
        BSTpair ans= new BSTpair();
        return ans;
    }
    BSTpair left=sol(root.left);
    BSTpair right=sol(root.right);

    BSTpair myans= new  BSTpair(); 
    if(left.isBST&&right.isBST&&(root.data>left.max&&root.data<=right.min)){
      myans.count++;

    }

}
}