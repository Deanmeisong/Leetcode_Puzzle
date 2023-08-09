class Solution {
    public int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 0; i <= n; ++i) {
            if(helper(i)) ++ans;
        }
        return ans;
    }
    
    Boolean helper(int x) {
        boolean flag = false;
        while(x > 0) {
            int t = x % 10;
            x /= 10;
            if(t == 4 || t == 3 || t == 7) return false;
            if(t == 6 || t == 9 || t == 2 || t == 5) flag = true;
        }
        return flag;
    }
}