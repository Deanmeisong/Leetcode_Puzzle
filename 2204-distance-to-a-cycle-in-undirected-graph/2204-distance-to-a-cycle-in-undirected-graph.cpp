class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        vector<int> rets(n, 0);
        vector<vector<int>> next(n);
        vector<int> degree(n, 0);
        
        for(const auto& e : edges) {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; ++i)
            if(degree[i] == 1) q.push(i);
        
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            rets[cur] = -1;
            for(int nxt : next[cur]) {
                --degree[nxt];
                if(degree[nxt] == 1) q.push(nxt);
            }
        }
        
        queue<int> q2;
        for(int i = 0; i < n; ++i)
            if(rets[i] == 0) q2.push(i);
        
        while(!q2.empty()) {
            int cur = q2.front(); q2.pop();
            for(int nxt : next[cur]) {
                if(rets[nxt] != -1) continue;
                rets[nxt] = rets[cur] + 1;
                q2.push(nxt);
            }
        }
        
        return rets;
    }
};