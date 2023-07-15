class Solution {
public:
    int checkRecord(int n) {
        vector<vector<int>> dp(2, vector<int>(3, 0));
        dp[0][0] = 1;
        int kMod = 1e9 + 7;
        int ans = 0;
        
        for(int i = 1; i <= n; ++i) {
            // if p
            vector<vector<int>> tmp(2, vector<int>(3, 0));
            for(int j = 0; j < 2; ++j)
                for(int k = 0; k < 3; ++k) 
                    tmp[j][0] = (tmp[j][0] + dp[j][k]) % kMod;
            
            // if a
            for(int k = 0; k < 3; ++k) tmp[1][0] = (tmp[1][0] + dp[0][k]) % kMod;
            for(int j = 0; j < 2; ++j)
                for(int k = 1; k < 3; ++k) tmp[j][k] = (tmp[j][k] + dp[j][k - 1]) % kMod;
            
            dp = tmp;
        }
        
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 3; ++k)
                ans = (ans + dp[j][k]) % kMod;
    
        return ans;
        
    }
};