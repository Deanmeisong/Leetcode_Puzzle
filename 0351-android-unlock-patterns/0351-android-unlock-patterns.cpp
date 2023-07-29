class Solution {
public:
    int count = 0;
    int m, n;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1},{-1,2},{1,2},{-2,1},{2,1},{-1,-2},{1,-2},{-2,-1},{2,-1}};
    int visited[3][3];
    
    int numberOfPatterns(int m, int n) {
        this->m = m; this->n = n;
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j) {
                if(visited[i][j] == 0) {
                    visited[i][j] = 1;
                    dfs(i, j , 1);
                    visited[i][j] = 0;
                }
            }
        return count;
    }
    
    void dfs(int x, int y, int r) {

        if (r>=m && r<=n)
            count++;
        if (r>n) return;

        
        for(int k = 0; k <dirs.size(); ++k) {
            int i = x + dirs[k][0];
            int j = y + dirs[k][1];
            if(i < 0 or i >= 3 or j < 0 or j >= 3) continue;
            if(visited[i][j] == 0) {
                visited[i][j] = 1;
                dfs(i, j, r + 1);
                visited[i][j] = 0;
            } else {
                i = i + dirs[k][0];
                j = j + dirs[k][1];
                if(i < 0 or i >= 3 or j < 0 or j >= 3) continue;
                if(visited[i][j] == 1) continue;
                visited[i][j] = 1;
                dfs(i, j, r + 1);
                visited[i][j] = 0;
            }
        }
    }
};