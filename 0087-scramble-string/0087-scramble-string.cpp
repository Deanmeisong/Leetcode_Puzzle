class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if(s1 == s2) return true;
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
        
        for(int k = 1; k <= n; ++k) {
            for(int i = 0; i + k - 1< n; ++i) {
                for(int j = 0; j + k - 1< n; ++j) {
                    if(k == 1) {
                        dp[i][j][k] = s1[i] == s2[j];
                        continue;
                    }
                    
                    for(int u = 1; u < k; ++u) {
                        bool o1 = dp[i][j][u] && dp[i + u][j + u][k - u];
                        bool o2 = dp[i][j + k - u][u] && dp[i + u][j][k - u];
                        if(o1 || o2) {
                            dp[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return dp[0][0][n];
            
    }
};