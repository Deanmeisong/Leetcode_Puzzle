class Solution {
public:
    int dp[16][65536] = {};
    int maximumCost(int n, vector<vector<int>>& highways, int k) {
        if(k > n - 1) return -1;
        int ans = INT_MIN;
        
        vector<vector<array<int, 2>>> adj(n);
        
        for(const auto& h : highways) {
            adj[h[0]].push_back({h[1], h[2]});
            adj[h[1]].push_back({h[0], h[2]});
        }
        
        function<int(int, int, int)> dfs = [&](int i, int mask, int k1)->int {
            if(k1 == 0) return 0;
            if(dp[i][mask] == 0) {
                dp[i][mask] = INT_MIN;
                for(auto [j, cost] : adj[i])
                    if(((1<<j) & mask) == 0) dp[i][mask] = max(dp[i][mask], cost + dfs(j, mask + (1<<j), k1 - 1));
            }
            return dp[i][mask];
        };
        
        for(int i = 0; i < n; ++i)
            ans = max(ans, dfs(i, (1<<i), k));
        
        return ans < 0 ? -1 : ans;
    }

};