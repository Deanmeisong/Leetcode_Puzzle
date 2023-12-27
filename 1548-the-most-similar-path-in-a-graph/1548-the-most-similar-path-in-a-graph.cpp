class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        int m = targetPath.size();
        vector<vector<int>> dp(m, vector<int>(n, m + 1));
        vector<vector<int>> p(m, vector<int>(n));
        
        for(int i = 0; i < n; ++i) dp[0][i] = names[i] != targetPath[0];
        for(int i = 1; i < m; ++i)
            for(auto road : roads) {
                for(int j = 0; j < 2; ++j) {
                    int u = road[j], v = road[j ^ 1], cur = dp[i - 1][u] + (names[v] != targetPath[i]);
                    if(cur < dp[i][v]) {
                        dp[i][v] = cur;
                        p[i][v] = u;
                    }
                }
            }
      
        int v = min_element(dp.back().begin(), dp.back().end()) - dp.back().begin();
        vector<int> ans{v};
        for(int i = m - 1; i > 0; --i) {
            v = p[i][v];
            ans.push_back(v);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};