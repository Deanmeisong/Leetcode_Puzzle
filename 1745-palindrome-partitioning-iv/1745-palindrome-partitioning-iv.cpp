class Solution {
    int dp[2000][2000];
public:
    bool checkPartitioning(string s) {
        int n = s.length();
        for(int i = 0; i < n; ++i) dp[i][i] = 1;
        for(int i = 0; i + 1 < n; ++i) dp[i][i + 1] = (s[i] == s[i + 1]);
        for(int len = 3; len <= n; ++len)
            for(int i = 0; i + len - 1 < n; ++i)
                dp[i][i + len - 1] = (s[i] == s[i + len - 1] && dp[i + 1][i + len - 2]);
        
        for(int i = 1; i < n; ++i)
            for(int j = i; j + 1 < n; ++j)
                if(dp[0][i - 1] && dp[i][j] && dp[j + 1][n - 1]) return true;
        return false;
    }
};