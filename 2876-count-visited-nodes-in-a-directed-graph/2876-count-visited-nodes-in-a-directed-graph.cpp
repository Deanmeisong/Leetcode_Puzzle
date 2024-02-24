class Solution {
public:
    int next[100005];
    int indegree[100005];
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> rets(n);
        for(int i = 0; i < n; ++i) {
            next[i] = edges[i];
            indegree[edges[i]] += 1;
        }
        queue<int> q;
        for(int i = 0; i< n; ++i) 
            if(indegree[i] == 0) q.push(i);
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int cur = q.front(); q.pop();
                int nxt = next[cur];
                if(--indegree[nxt] == 0) q.push(nxt);
            }
        }
        
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) continue;
            if(rets[i] != 0) continue;
            int len = 1;
            int j = i;
            while(next[j] != i) {
                len++;
                j = next[j];
            }
            j = i;
            while(next[j] != i) {
                rets[j] = len;
                j = next[j];
            }

        }
        
        function<int(int)> dfs = [&](int cur) {
            if(rets[cur] != 0) return rets[cur];
            rets[cur] = dfs(next[cur]) + 1;
            return rets[cur];
        };
        
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) dfs(i);
        }
        
        return rets;
    }
};