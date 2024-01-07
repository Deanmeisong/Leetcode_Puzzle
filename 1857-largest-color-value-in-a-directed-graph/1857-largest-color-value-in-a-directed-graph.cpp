class Solution {
public:
    typedef array<int, 26> T;
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> G;
        vector<int> indegrees(colors.size());
        vector<T> cnt(colors.size(), T{});
        
        for(const auto& e : edges) {
            G[e[0]].push_back(e[1]);
            ++indegrees[e[1]];
        }
        
        queue<int> q;
        for(int i = 0; i < colors.size(); ++i) {
            if(indegrees[i] == 0) {
                q.push(i);
                cnt[i][colors[i] - 'a'] = 1;
            }
        }
        
        int ans = 0, seen = 0;
        
        while(!q.empty()) {
            int len = q.size();
            ++seen;
            
            int u = q.front(); q.pop();
            int val = *max_element(cnt[u].begin(), cnt[u].end());
            ans = max(val, ans);

            for(const int v : G[u]) {
                for(int i = 0; i < 26; ++i) {
                    cnt[v][i] = max(cnt[v][i], cnt[u][i] + (colors[v] - 'a' == i));
                }
                if(--indegrees[v] == 0) q.push(v);
            }
            
        }
        
        return seen < colors.size() ? -1 : ans;
    }
};