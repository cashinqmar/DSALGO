import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

class removeparenthesis2 {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();

        HashSet<String> vmans = new HashSet<String>();

        ArrayList<String> vmans1 = new ArrayList<String>();
        

        find(str, vmans, vmans1);
        int limit=(int) -1e8;
        for(String s: vmans1){
            limit=Math.max(limit,s.length());
        }

        for(String s: vmans1){
            if(limit==s.length())System.out.println(s);
        }
           
    }
    static int limit = Integer.MIN_VALUE;
    
    public static void find(String str, HashSet<String> vmans, ArrayList<String> vmans1) {
        if (str.equals("")) {
            return;
        }
        if (isValidString(str) && str.length() >= limit && !vmans.contains(str)) {
            vmans.add(str);
            limit = str.length();
            vmans1.add(str);
            return;
        }

        for (int i = 0; i < str.length(); i++) {
            String temp = str.substring(0, i) + str.substring(i + 1, str.length());
            find(temp, vmans, vmans1);
        }

        return;
    }

   static boolean isValidString(String str) {
        int cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(')
                cnt++;
            else if (str.charAt(i) == ')')
                cnt--;
            if (cnt < 0)
                return false;
        }
        return (cnt == 0);
    }
}