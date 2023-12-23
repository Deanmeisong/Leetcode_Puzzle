class Solution {
    public int minFallingPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
       
        int[][] dp = new int[m][n];
  
        for (int i = 0; i < n; i++) {
            dp[0][i] = grid[0][i];
        }
        for (int r = 1; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int min_value = Integer.MAX_VALUE;
                for (int k = 0; k < n; k++) {
                    if (k == c) {
                        continue;
                    }
                    min_value = Math.min(min_value, dp[r - 1][k]);
                }
                dp[r][c] = grid[r][c] + min_value;
            }
        }
        
        int ret = dp[m-1][0];
        for(int x : dp[m - 1])
            ret = Math.min(ret, x);
        return ret;
    }
}