class Solution {
    public int numWays(int steps, int arrLen) {
        int n = Math.min(steps/2+2, arrLen);
        long[] dp = new long[n];
        long M = 1000000007;
        dp[0] = 1;
        for (int k=0; k<steps; k++) {
            long[] dp2 = Arrays.copyOf(dp, n);
            for (int i=0; i<n; i++) {
                dp[i] = dp2[i] + (i>=1 ? dp2[i-1]:0) + (i+1<n ? dp2[i+1] : 0);
                dp[i] %= M;
            }
        }
        return (int)dp[0];
    }
} 