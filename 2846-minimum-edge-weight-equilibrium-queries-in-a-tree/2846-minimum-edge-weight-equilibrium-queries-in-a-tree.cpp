class Solution {
public:
    vector<pair<int,int>> next[10005];
    int parent[10005];
    int level[10005];
    int count[10005][27];

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for(auto& e : edges) {
            int a = e[0], b = e[1], c = e[2];
            next[a].push_back({b, c});
            next[b].push_back({a, c});
        }
        
        vector<int> temp(27);
        dfs(0, -1, 0, temp);
        parent[0] = -1;
        vector<int> rets;
       
        for(auto q : queries) {
            int a = q[0], b = q[1];
            int lca = getLCA(a, b);
            vector<int> temp(27);
            for(int i = 1; i <= 26; ++i) {
                temp[i] += count[a][i];
                temp[i] += count[b][i];
                temp[i] -= 2*count[lca][i];
            }

            int mx = 0;
            int sum = 0;
            for(int i = 1; i <= 26; ++i) {
                mx = max(mx, temp[i]);
                sum += temp[i];
            }
            rets.push_back(sum-mx);
        }
        
        return rets;
    }
    
    void dfs(int cur, int p, int l, vector<int>& temp) {
        for(auto& child : next[cur]) {
            if(child.first == p) continue;
            ++temp[child.second];
            for(int i = 1; i < 27; ++i) count[child.first][i] = temp[i];
            level[child.first] = l + 1;
            parent[child.first] = cur;
            dfs(child.first, cur, l+1, temp);
            --temp[child.second];
        }
    }
    
    int getLCA(int p, int q) {
        while(1) {
            if(level[p] > level[q]) {
                p = parent[p];
            } else if(level[p] < level[q]) {
                q = parent[q];
            } else if(p == q) {
                return p;
            } else {
                p = parent[p];
                q = parent[q];
            }
        }

        return 0;
    }
};