class Solution {
public:
    vector<int> next[100005];
    unordered_set<int> g[100005];
    int k;
    int ret;
    int count;
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        this->k = k;
        for(auto e : edges) {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        for(auto guess : guesses) {
            g[guess[0]].insert(guess[1]);
        }
        count = dfs(0, -1);
        dfs2(0, -1, count);
        return ret;
    }
    
    int dfs(int cur, int parent) {
        int cnt = 0;
        for(int nxt : next[cur]) {
            if(nxt == parent) continue;
            cnt += dfs(nxt, cur);
            if(g[cur].find(nxt) != g[cur].end()) ++cnt;
        }
        return cnt;
    }
    
    void dfs2(int cur, int parent, int count) {
        if(count >= k) ++ret;
        for(int nxt : next[cur]) {
            if(nxt == parent) continue;
            int tmp = count;
            if(g[cur].find(nxt) != g[cur].end()) --tmp;
            if(g[nxt].find(cur) != g[nxt].end()) ++tmp;
            dfs2(nxt, cur, tmp);
        }
    }
};