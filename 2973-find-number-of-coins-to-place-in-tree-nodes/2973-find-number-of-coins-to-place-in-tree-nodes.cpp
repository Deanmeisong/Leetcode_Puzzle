using LL = long long;
class Solution {
public:
    vector<int> children[20005];
    vector<int> next[20005];
    vector<LL> rets;
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }
        int n = cost.size();
        rets.resize(n);
        dfs(0, -1, cost);
        return rets;
    }
    
    void dfs(int cur, int parent, vector<int>& cost) {
        vector<LL> tmp;
        for(int nxt : next[cur]) {
            if(nxt == parent) continue;
            dfs(nxt, cur, cost);
            for(int x: children[nxt]) tmp.push_back(x);
        }
        tmp.push_back(cost[cur]);
        int n = tmp.size();
        sort(tmp.begin(), tmp.end());
        if(tmp.size() < 3) rets[cur] = 1;
        else rets[cur] = max(0LL, max(tmp[n-1]*tmp[n-2]*tmp[n-3], tmp[0]*tmp[1]*tmp[n-1]));
        
        if(n >= 1) children[cur].push_back(tmp[0]);
        if(n >= 2) children[cur].push_back(tmp[1]);
        if(n >= 5) children[cur].push_back(tmp[n-3]);
        if(n >= 4) children[cur].push_back(tmp[n-2]);
        if(n >= 3) children[cur].push_back(tmp[n-1]);
        
    }
};