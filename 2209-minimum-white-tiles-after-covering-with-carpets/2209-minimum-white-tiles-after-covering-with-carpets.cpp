class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.length();
        vector<vector<int>> dp(n + 1, vector<int>(numCarpets + 1, INT_MAX/2));
        for(int j = 0; j < numCarpets; ++j) dp[0][j] = 0;
        floor = "#" + floor;
        for(int i = 1; i <= n; ++i) 
            for(int j = 0; j <= numCarpets; ++j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (floor[i] == '1'));
                if(j > 0) dp[i][j] = min(dp[i][j], i - carpetLen <= 0 ? 0 : dp[i - carpetLen][j - 1]);
            }
        return dp[n][numCarpets];
    }
};