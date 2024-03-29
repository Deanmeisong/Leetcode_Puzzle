using AI3 = array<int, 3>;
using LL = long long;
LL M = 1e9 + 7;
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<AI3> arr;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                arr.push_back({grid[i][j], i, j});
        
        sort(arr.begin(), arr.end());
        vector<vector<LL>> dp(m, vector<LL>(n));
        LL ret = 0;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto[value, i, j] : arr) {
            LL sum = 0;
            for(int k = 0; k < 4; ++k) {
                int x = i + dirs[k].first;
                int y = j + dirs[k].second;
                if(x < 0 || x >= m || y < 0 || y >= n) continue;
                if(grid[x][y] >= grid[i][j]) continue;
                sum = (sum + dp[x][y]) % M;
            }
            sum += 1;
            dp[i][j] = sum;
            ret = (ret + sum) % M;
        }
    
        return ret;
    }
};