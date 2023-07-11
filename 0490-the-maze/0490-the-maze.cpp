class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<vector<int>> q;
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        q.push(start);
        while(!q.empty()) {
            auto pos = q.front(); q.pop();
            int x = pos[0], y = pos[1];
            maze[x][y] = 2;
            if(x == destination[0] and y == destination[1]) return true;
            for(int i = 0; i < 4; ++i) {
                int r = dirs[i][0]; int c = dirs[i][1];
                int nx = x + r, ny = y + c;
                while(nx >= 0 and nx < m and ny >= 0 and ny < n and maze[nx][ny] != 1) {
                    nx += r; ny += c;
                }
                nx -= r; ny -= c;
                if(maze[nx][ny] == 0) q.push({nx, ny});
            }
        }
        return false;
    }
};