class Diff2d {
public:
    vector<vector<int>> f;
    vector<vector<int>> diff;
    int m, n;
    Diff2d(vector<vector<int>>& A) {
        m = A.size(); n = A[0].size();
        diff.resize(m + 1); f.resize(m + 1);
        for(int i = 0; i < m + 1; ++i) {
            diff[i].resize(n + 1);
            f[i].resize(n + 1);
        }
    }
    
    void set(int x1, int y1, int x2, int y2) {
        diff[x1][y1] += 1;
        diff[x2 + 1][y1] -= 1;
        diff[x1][y2 + 1] -= 1;
        diff[x2 + 1][y2 + 1] += 1;
    }
  
    void compute() {
        f[0][0] = diff[0][0];
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                            
                int a = i == 0 ? 0 : f[i - 1][j];
                int b = j == 0 ? 0 : f[i][j - 1];
                int c = (i == 0 || j == 0) ? 0 : f[i - 1][j - 1];
                f[i][j] = a + b - c + diff[i][j];
            }
    }
    
};

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(); int n = grid[0].size();
        Diff2d Grid(grid);
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) 
        {
                if(grid[i][j] == 0) continue;
                int x = min(i + stampHeight - 1, m - 1);
                int y = min(j + stampWidth - 1, n - 1);
                Grid.set(i, j, x, y);
            }
        Grid.compute();
        
        Diff2d Stamps(grid);
        for(int x = m - 1; x - stampHeight + 1>= 0; --x)
            for(int y = n - 1; y - stampWidth + 1 >= 0; --y) {
                if(Grid.f[x][y]) continue;
                int i = x - stampHeight + 1; int j = y - stampWidth + 1;
                Stamps.set(i, j, x, y);
            }
        Stamps.compute();
        
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == 0 && Stamps.f[i][j] == 0) return false;

        
        return true;
    }
};