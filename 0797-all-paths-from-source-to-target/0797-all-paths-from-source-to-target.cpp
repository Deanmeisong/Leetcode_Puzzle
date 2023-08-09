class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int t = int(g.size() - 1);
        vector<vector<int>> res;
        vector<int> p{0};

        function<void(int)> dfs = [&](int cur) {
            if(cur == t) {
                res.push_back(p);
                return;
            }

            for(int next : g[cur]) {
                p.push_back(next);
                dfs(next);
                p.pop_back();
            }
        };

        dfs(0);
        return res;
    }
};