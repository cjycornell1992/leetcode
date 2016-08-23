public class Solution {
    boolean negative = false;
    public int reverse(int x) {
        if (x == Integer.MIN_VALUE) return 0;
        if (x < 0){
            negative = true;
            x = -x;
        } 
        
        x = reverseHelper(x);
        if(negative) return -x;
        else return x;
    }
    
    private int reverseHelper(int x){
        long a = 0;
        while(x >= 10){
            a = 10*(a + (x % 10));
            if(a >= Integer.MAX_VALUE)   return 0;
            x = x/10;
        }
        a+= x;
        return (int) a;
    }
}