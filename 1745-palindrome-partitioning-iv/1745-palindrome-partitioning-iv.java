class Solution {
    public boolean checkPartitioning(String s) {
        int n = s.length();
        char[] A = s.toCharArray();
        Boolean[][] dp = new Boolean [n][n];
        
        for(int i = n - 1; i >= 0; --i)
            for(int j = i; j < n; ++j)
                if(A[i] == A[j]) dp[i][j] = ((i + 1 <= j - 1) ? dp[i + 1][j - 1] : true);
                else dp[i][j] = false;
        
        
        for(int i = 1; i < n; ++i)
            for(int j = i; j < n - 1; ++j)
                if(dp[0][i - 1] && dp[i][j] && dp[j + 1][n - 1]) return true;
        
        return false;
    }
}