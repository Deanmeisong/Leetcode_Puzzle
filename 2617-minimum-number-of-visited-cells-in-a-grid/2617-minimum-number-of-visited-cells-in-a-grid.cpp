using PII = pair<int,int>;
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX/2));
        vector<priority_queue<PII, vector<PII>, greater<>>> rd(m);
        vector<priority_queue<PII, vector<PII>, greater<>>> cd(n);
        vector<multiset<int>> rs(m); vector<multiset<int>> cs(n);
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                while(!rd[i].empty() && rd[i].top().first == j) {
                    int x = rd[i].top().second;
                    rd[i].pop();
                    if(x > 0) rs[i].insert(x);
                    if(x < 0) rs[i].erase(rs[i].find(-x));
                }
                while(!cd[j].empty() && cd[j].top().first == i) {
                    int y = cd[j].top().second;
                    cd[j].pop();
                    if(y > 0) cs[j].insert(y);
                    if(y < 0) cs[j].erase(cs[j].find(-y));
                }
                int minV = INT_MAX/2;
                if(!rs[i].empty()) minV = min(minV, *rs[i].begin());
                if(!cs[j].empty()) minV = min(minV, *cs[j].begin());
                dp[i][j] = minV;
                if(i == 0 && j == 0) dp[i][j] = 0;
                
                int step = grid[i][j];
                if(step == 0) continue;
                rd[i].push({j+1, dp[i][j] + 1});
                rd[i].push({j+step+1, -(dp[i][j] + 1)});
                cd[j].push({i+1, dp[i][j] + 1});
                cd[j].push({i+step+1, -(dp[i][j] + 1)});
            }
        if(dp[m-1][n-1] == INT_MAX/2) return -1;
        return dp[m-1][n-1] + 1;
    }
};