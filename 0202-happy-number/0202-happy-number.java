class Solution {
    public boolean isHappy(int n) {
        Set<Integer> dp = new HashSet<>();
        while(dp.add(n)) {
            int sq = 0;
            while(n > 0) {
                int base = n % 10;
                sq += base * base;
                n /= 10;
            }
            if(sq == 1) return true;
            n = sq;
        }
        
        return false;
    }
}