class Solution {
    public int lastStoneWeightII(int[] A) {
        boolean[] dp = new boolean[1501];
        dp[0] = true;
        int sum = 0;
        for(int a : A) {
            sum += a;
            for(int i = Math.min(sum, 1500); i >= a; --i) {
                dp[i] |= dp[i-a];
            }
        }
        
        for(int i = sum/2; i >= 0; --i)
            if(dp[i]) return sum - 2*i;
        return 0;
    }
}