class Solution {
public:
    int minimumSeconds(vector<vector<string>>& land) {
        int m = land.size(), n = land[0].size();
        int g[m][n];
        bool vis[m][n];
        memset(g, 0x3f, sizeof(g));
        memset(vis, false, sizeof(vis));
        int si = 0, sj = 0;
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                auto c = land[i][j];
                if (c == "*") {
                    q.emplace(i, j);
                } else if (c == "S") {
                    si = i;
                    sj = j;
                }
            }
        
        int dirs[5] = {-1, 0, 1, 0, -1};
        for(int t = 0; !q.empty(); ++t) {
            for(int k = q.size(); k; --k) {
                auto [i, j] = q.front(); q.pop(); g[i][j] = t;
                for(int d = 0; d < 4; ++d) {
                    int x = i + dirs[d]; int y = j + dirs[d+1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                        bool empty = land[x][y] == ".";
                        bool start = land[x][y] == "S";
                        if (empty || start) {
                            vis[x][y] = true;
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }
        

        memset(vis, false, sizeof(vis));
        q.emplace(si, sj);
        vis[si][sj] = true;
        
        for(int t = 0; !q.empty(); ++t) {
            for(int k = q.size(); k; --k) {
                auto [i, j] = q.front(); q.pop();
                if(land[i][j] == "D") return t;
                for(int d = 0; d < 4; ++d) {
                    int x = i + dirs[d]; int y = j + dirs[d+1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && g[x][y] > t + 1) {
                        bool empty = land[x][y] == ".";
                        bool dest = land[x][y] == "D";
                        if (empty || dest) {
                            vis[x][y] = true;
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};