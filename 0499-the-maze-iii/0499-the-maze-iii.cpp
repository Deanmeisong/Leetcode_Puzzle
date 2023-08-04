using TP = tuple<int, string, int, int>;
class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    int m; int n;
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        m = maze.size(); n = maze[0].size();
        priority_queue<TP, vector<TP>, greater<>> q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        q.push({0, "", ball[0], ball[1]});
        string ret;
        
        while(!q.empty()) {
            auto [d, s, x, y] = q.top(); q.pop();
            if(d > dist[x][y]) continue;
            else dist[x][y] = d;
            
            if(x == hole[0] && y == hole[1]) {
                ret = s; break;
            }
            
            for(int k = 0; k < 4; ++k) {
                int step = next(k, x, y, hole, maze);
                int nx = x + dirs[k].first * step; int ny = y + dirs[k].second * step;
                char ch = '0' + k;
                if(d + step >= dist[nx][ny]) continue;
                else q.push({d + step, s + ch, nx, ny});
            }
            
        }
        
        string res;
        for(int i = 0; i < ret.size(); ++i) {
            if(ret[i] == '0') res += 'd'; if(ret[i] == '1') res += 'l'; if(ret[i] == '2') res += 'r'; if(ret[i] == '3') res += 'u';
        }
        
        if(res == "") return "impossible";
        else return res;
    }
    
    int next(int k, int x, int y, vector<int> hole, vector<vector<int>> maze) {
        int step = 0;
        while (x+dirs[k].first >= 0 && x+dirs[k].first < m && y+dirs[k].second >= 0 && y+dirs[k].second < n && maze[x+dirs[k].first][y+dirs[k].second]!=1)
        {            
            step++;
            x+=dirs[k].first;
            y+=dirs[k].second;
            if (x==hole[0] && y==hole[1])
                break;
        }
        return step;
    }
    
};