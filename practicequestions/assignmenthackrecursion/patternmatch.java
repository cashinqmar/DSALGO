import java.util.*;
class patternmatch{

    public static void main(String[] args) {
        HashMap<Character,String> map=new HashMap<Character,String>();
       String s; 
		Scanner sc = new Scanner(System.in);
 		String str = sc.nextLine();  
         String pat=sc.nextLine();
        find(str,0,pat,0,map);
    }

public static boolean find(String str,int index,String pattern,int pi,HashMap<Character,String>map)
    {
        if(index==str.length()||pi==pattern.length())
        {
            if(index==str.length()&&pi==pattern.length())
            {
             System.out.println(map);
                return true;
            }
              return false ;
        }
        boolean res=false;    
        
          char patternchar =pattern.charAt(pi);
        
            if(map.containsKey(patternchar))
            {
                String temp=map.get(patternchar);
                if(index+temp.length()<=str.length())
                {
                    String temp1=str.substring(index,index+temp.length());
                    if(temp1.equals(temp))
                    {
                       res= find(str,index+temp.length(),pattern,pi+1,map);
                    }
                } 
            }
        
        else
        {

            String tempstr="";
            for(int i=index;i<str.length();i++)
            {
                    tempstr+=str.charAt(i);
                    map.put(pattern.charAt(pi),tempstr);
                   res= find(str,index+tempstr.length(),pattern,pi+1,map);
                    map.remove(pattern.charAt(pi));
                    res=false;
             }
        }
        return res;
}
}