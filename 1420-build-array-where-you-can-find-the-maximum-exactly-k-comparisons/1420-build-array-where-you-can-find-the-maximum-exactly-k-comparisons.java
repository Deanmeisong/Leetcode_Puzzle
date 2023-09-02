class Solution {
    public int numOfArrays(int n, int m, int k) {
        Integer[][][] dp = new Integer[n + 1][m + 1][k + 1];
        return dfs(n, m, k, 0, 0, 0, dp);
    }
    
    int dfs(int n, int m, int k, int i, int currMax, int currCost, Integer[][][] dp) {
        if(i == n) {
            if(currCost == k) return 1;
            return 0;
        }
        
        if(dp[i][currMax][currCost] != null) return dp[i][currMax][currCost];
        
        int res = 0;
        for(int j = 1; j <= m; ++j) {
            int newCost = currCost; int newMax = currMax;
            if(j > currMax) {
                newMax = j;
                ++newCost;
            }
            if(newCost > k) break;
            res += dfs(n, m, k, i + 1, newMax, newCost, dp);
            res %= 1_000_000_007;
        }
        
        return dp[i][currMax][currCost] = res;

    }
}