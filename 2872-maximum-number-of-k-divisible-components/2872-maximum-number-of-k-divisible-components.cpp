class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> g[n];
        for(auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans = 0;
        function<long long(int, int)> dfs = [&](int cur, int parent) {
            long long s = values[cur];
            for(int nxt : g[cur]) {
                if(nxt != parent) {
                    s += dfs(nxt, cur);
                }
            }
            ans += (s % k == 0);
            return s;
        };
        
        dfs(0, -1);
        return ans;
    }
};