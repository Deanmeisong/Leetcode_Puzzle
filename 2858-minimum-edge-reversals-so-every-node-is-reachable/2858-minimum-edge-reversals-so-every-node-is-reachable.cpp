class Solution {
public:
    vector<pair<int, int>> nexts[100005];
    vector<int> rets;
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        rets.resize(n);
        for(auto& e : edges) {
            int a = e[0], b = e[1];
            nexts[a].push_back({b, 1});
            nexts[b].push_back({a, -1});
        }
        int count = dfs(0, -1);
        dfs2(0, -1, count);
        return rets;
    }
    
    int dfs(int cur, int father) {
        int count = 0;
        for(auto [next, dir] : nexts[cur]) {
            if(next == father) continue;
            int cnt = dfs(next, cur);
            if(dir == 1) count += cnt;
            else count += cnt + 1;
        }
        return count;
    }
    
    void dfs2(int cur, int father, int count) {
        rets[cur] = count;
        for(auto [next, dir] : nexts[cur]) {
            if(next == father) continue;
            if(dir == 1) dfs2(next, cur, count + 1);
            else dfs2(next, cur, count - 1);
        }
    }
};