class Solution {
public:
    int dp[505][505*2];
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        cost.insert(cost.begin(), 0);
        time.insert(time.begin(), 0);
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= n; ++j) {
                dp[i][j] = INT_MAX/2;
            }
        dp[0][0] = 0;
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j <= n; ++j) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                int k = min(n, j + time[i+1] + 1);
                dp[i+1][k] = min(dp[i+1][k], dp[i][j] + cost[i+1]);
            }
        return dp[n][n];
    }
};