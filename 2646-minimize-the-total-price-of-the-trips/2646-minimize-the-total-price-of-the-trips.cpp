class Solution {
public:
    int count[55];
    int opt0[55];
    int opt1[55];
    int values[55];
    vector<int> next[55];
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        for(auto e : edges) {
            int a = e[0]; int b = e[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }
        for(int i = 0; i < n; ++i) {
            opt0[i] = -1;
            opt1[i] = -1;
        }
        for(auto tr : trips)
            dfs(tr[0], -1, tr[1]);
        for(int i = 0; i < n; ++i)
            values[i] = price[i]*count[i];
        return DFS(0, -1, 1);
    }
    
    bool dfs(int cur, int parent, int target) {
        if(cur == target) {
            ++count[cur];
            return true;
        }
        for(int nxt : next[cur]) {
            if(nxt == parent) continue;
            if(dfs(nxt, cur, target)) {
                ++count[cur];
                return true;
            }
        }
        return false;
    }
    
    int DFS(int cur, int parent, int flag) {
        if(flag == 0 && opt0[cur] != -1) return opt0[cur];
        if(flag == 1 && opt1[cur] != -1) return opt1[cur];
        int ret = 0;
        // int option0 = INT_MAX/2; int option1 = INT_MAX/2;
        if(flag == 0) {
            ret += values[cur];
            for(int nxt : next[cur]) {
                if(nxt == parent) continue;
                ret += DFS(nxt, cur, 1);
            }
            opt0[cur] = ret;
            return ret;
        } else {
            int subOpt0 = values[cur];
            for(int nxt : next[cur]) {
                if(nxt == parent) continue;
                subOpt0 += DFS(nxt, cur, 1);
            }
            int subOpt1 = values[cur]/2;
            for(int nxt : next[cur]) {
                if(nxt == parent) continue;
                subOpt1 += DFS(nxt, cur, 0);
            }
            ret = min(subOpt0, subOpt1);
            opt1[cur] = ret;
            return ret;
        }
        
    }
};