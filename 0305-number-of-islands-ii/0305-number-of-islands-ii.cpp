class UnionFind {
private:
    vector<int> parent, rank;
    int count;
    
public:
    UnionFind(int size) {
        parent.resize(size, -1);
        rank.resize(size, -1);
        count = 0;
    }
    
    void addLand(int x) {
        if(parent[x] >= 0) return;
        parent[x] = x;
        ++count;
    }
    
    bool isLand(int x) {
        return parent[x] >= 0;
    }
    
    int numOfIslands() {return count;}
    
    int find(int x) {
        if(x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void union_set(int x, int y) {
        int xs = find(x), ys = find(y);
        if(xs == ys) return;
        else if(rank[xs] < rank[ys]) parent[xs] = ys;
        else if(rank[xs] > rank[ys]) parent[ys] = xs;
        else {
            parent[ys] = xs;
            rank[xs]++;
        }
        --count;
    }
};

class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int s = m * n;
        UnionFind dsu(s);
        vector<int> ans;
        
        for(auto p : positions) {
            int lp = p[0] * n + p[1];
            dsu.addLand(lp);
            for(int i = 0; i < 4; ++i) {
                int nx = p[0] + dir[i][0];
                int ny = p[1] + dir[i][1];
                int np = nx * n + ny;
                
                if(nx >= 0 and nx < m and ny >= 0 and ny < n and dsu.isLand(np)) {
                    dsu.union_set(lp, np);
                }
            }
            ans.push_back(dsu.numOfIslands());
        }
        return ans;
    }
};