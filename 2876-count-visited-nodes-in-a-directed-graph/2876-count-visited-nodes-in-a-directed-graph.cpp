class Solution {
public:
    int next[100005];
    int indegree[100005];
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> ret(n);

        for(int i = 0; i < n; ++i) {
            next[i] = edges[i];
            ++indegree[next[i]];
        }
        
        queue<int> q;
        for(int i = 0; i < n; ++i)
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
            if(ret[i] != 0) continue;
            
            int j = i;
            int len = 1;
            while(next[j] != i) {
                j = next[j];
                ++len;
            }
            
            j = i;
            while(next[j] != i) {
                ret[j] = len;
                j = next[j];
            }
        }

        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) dfs(i, ret);
        }
        
        return ret;
    }
    
    int dfs(int cur, vector<int>& ret) {
        if(ret[cur] != 0) return ret[cur];
        ret[cur] = dfs(next[cur], ret) + 1;
        return ret[cur];
    }
};