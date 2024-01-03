class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for(int len = 2; len <= n; ++len)
            for(int i = 0, j = i + len - 1; j < n; ++i, ++j)
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
        for(int i = 1; i < n; ++i)
            for(int j = i; j + 1 < n; ++j)
                if(dp[0][i - 1] && dp[i][j] && dp[j + 1][n - 1]) return true;
        return false;

    }
};