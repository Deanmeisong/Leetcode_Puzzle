using LL = long long;
LL M = 1e9 + 7;
class Solution {
public:
    int dp[1000][1000];
    vector<vector<int>> grid;
    int m; int n;
    
    int countPaths(vector<vector<int>>& grid) {
        this->grid = grid;
        this->m = grid.size(); this->n = grid[0].size();
        LL ret = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j) {
               ret = (ret + dfs(i, j)) % M;
            }
        }
        return ret;
    }
    
    int dfs(int i, int j) {
        if(dp[i][j] != 0) return dp[i][j];
        vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        dp[i][j] = 1;
        for(int k = 0; k < 4; ++k) {
            int x = dirs[k].first + i; int y = dirs[k].second + j;
            if(x < 0 || x >= m || y < 0 || y >= n) continue;
            if(grid[x][y] >= grid[i][j]) continue;
            dp[i][j] += dfs(x, y);
            dp[i][j] %= M;
        }
        return dp[i][j];
    }
};