struct Node {
    int px, py, bx, by;
    int key() const {
        return ((by * 20 + bx) << 16) | (py * 20 + px); 
    }
};
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        Node start; Node end;
        for(int y = 0; y < n; ++y)
            for(int x = 0; x < m; ++x)
                if(grid[y][x] == 'S') {start.px = x; start.py = y;}
                else if(grid[y][x] == 'B') {start.bx = x; start.by = y;}
                else if(grid[y][x] == 'T') {end.bx = x; end.by = y;}
        
        auto hasPath = [&](const Node& cur, int tx, int ty) {
            vector<bool> seen(m*n);
            function<bool(int,int)> dfs = [&](int x, int y){
                if(x < 0 || x >= m || y < 0 || y >= n || grid[y][x] == '#') return false;
                if(x == cur.bx && y == cur.by) return false;
                if(seen[y*m+x]) return false;
                seen[y*m+x] = 1;
                if (x == tx && y == ty) return true;
                return dfs(x+1,y) || dfs(x-1,y) || dfs(x,y+1) || dfs(x,y-1);
            };
            return dfs(cur.px, cur.py);
        };
        
        
        auto canPush = [&](Node& cur, int dx, int dy, Node* nxt) {
            int bx = cur.bx + dx; int by = cur.by + dy;
            if(bx < 0 || bx >= m || by < 0 || by >= n || grid[by][bx] == '#') return false;
            if(!hasPath(cur, cur.bx-dx, cur.by-dy)) return false;
            nxt->bx = bx; 
            nxt->by = by; 
            nxt->px = cur.bx; 
            nxt->py = cur.by;   
            return true;
        };
        
        queue<Node> q;
        q.push(start);
        int step = 0;
        unordered_set<int> seen;
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                Node cur = q.front(); q.pop();
                for(int i = 0; i < 4; ++i) {
                    Node nxt;
                    if(!canPush(cur, dirs[i][0], dirs[i][1], &nxt) || seen.count(nxt.key())) continue;
                    if(nxt.by == end.by && nxt.bx == end.bx) return step+1;
                    seen.insert(nxt.key());
                    q.push(nxt);
                }
            }
            ++step;
        }
        
        return -1;
    }
};