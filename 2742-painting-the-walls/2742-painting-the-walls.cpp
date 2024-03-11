class Solution {
public:
    int dp[505][505*2];
    int offset = 505;
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        cost.insert(cost.begin(), 0);
        time.insert(time.begin(), 0);
        for(int i = 0; i <= n; ++i)
            for(int j =-n; j <= n; ++j) {
                dp[i][j+offset] = INT_MAX/2;
            }
        dp[0][offset] = 0;
        
        for(int i = 0; i < n; ++i)
            for(int j = -n; j <= n; ++j) {
                dp[i+1][j-1+offset] = min(dp[i+1][j-1+offset], dp[i][j+offset]);
                int k = min(n, j + time[i+1]);
                dp[i+1][k+offset] = min(dp[i+1][k+offset], dp[i][j+offset] + cost[i+1]);
            }
        int ret = INT_MAX/2;
        for(int j = 0; j <= n; ++j)
            ret = min(dp[n][j+offset], ret);
        return ret;
    }
};