class Solution {
    public boolean isPalindrome(int x) {
        
        if(x<0) {
            return false;
        }
        
        int remainder = 0;
        int oppositeX = 0;
        int temp = x;
            
        while(temp>0){
            remainder = temp % 10;
            oppositeX *= 10;
            oppositeX += remainder;
            temp = temp/10;
        }
        
        return (oppositeX == x);
    }
}