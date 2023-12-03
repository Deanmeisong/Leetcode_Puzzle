class Solution {
    long[][] dp = new long[51][1005];
    long M = 1000000007;

    public int waysToReachTarget(int target, int[][] types) {
        int n = types.length;
        int[][] newTypes = new int[n + 1][2];
        newTypes[0] = new int[]{0, 0};
        System.arraycopy(types, 0, newTypes, 1, n);

        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                for (int k = 0; k <= newTypes[i][0]; ++k) {
                    if (newTypes[i][1] * k > j) break;
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k * newTypes[i][1]]) % M;
                }
            }
        }
        return (int) dp[n][target];
    }
}
