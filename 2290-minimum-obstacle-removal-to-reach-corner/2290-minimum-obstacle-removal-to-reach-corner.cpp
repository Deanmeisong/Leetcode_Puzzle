class Solution {
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        if(m == 1 && n == 1) return 0;
        vector<vector<int>> visited(m, vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = 1;
        int step = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                auto [x,y] = q.front(); q.pop();
                for(auto [dx, dy] : dir) {
                    int i = x + dx; int j = y + dy;
                    if(i<0||i>=m||j<0||j>=n) continue;
                    if(visited[i][j]) continue;
                    if(grid[i][j] == 1) {
                        visited[i][j] = 1; q.push({i,j});
                    } else {
                        for(auto [ii,jj] : travel(grid, visited, i, j)) {
                            if(ii == m - 1 && jj == n- 1) return step;
                            q.push({ii,jj});
                        }
                    }
                }
            }
            ++step;
        }
        return 0;
    }
    
    vector<pair<int,int>> travel(vector<vector<int>>& grid, vector<vector<int>>& visited, int x0, int y0) {
        int m = grid.size(); int n = grid[0].size();
        if(x0 == m-1 && y0 == n-1) return {{x0, y0}};
        visited[x0][y0] = 1;
        queue<pair<int,int>> q;
        q.push({x0,y0});
        vector<pair<int,int>> rets;
        
        while(!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            for(auto [dx, dy] : dir) {
                int xx = x + dx; int yy = y + dy;
                if(xx<0||xx>=m||yy<0||yy>=n) continue;
                if(visited[xx][yy] == 1) continue;
                visited[xx][yy] = 1;
                if(xx==m-1&&yy==n-1) rets.push_back({xx,yy});
                else if(grid[xx][yy] == 1) rets.push_back({xx,yy});
                else q.push({xx,yy});
            }  
        }
        
        return rets;
    }
    
   
};