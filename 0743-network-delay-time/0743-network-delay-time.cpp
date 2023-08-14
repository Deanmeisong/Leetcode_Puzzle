class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> ds(n + 1, INT_MAX);
        ds[k] = 0;
        for(int i = 0; i < n; ++i) {
            for(auto e : times) {
                int u = e[0]; int v = e[1]; int d = e[2];
                if(ds[u] != INT_MAX) {
                    if(ds[v] > ds[u] + d) ds[v] = ds[u] + d;
                }
            }
        }
        
        int res = 0;
        for(int i = 1; i <= n; ++i)
            res = max(res, ds[i]);
        
        return res == INT_MAX ? -1 : res;
    }
};