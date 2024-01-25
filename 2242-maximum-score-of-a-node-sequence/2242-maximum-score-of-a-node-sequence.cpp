class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        vector<set<pair<int, int>>> neighors(scores.size());
        for(const auto& e : edges) {
            int a = e[0], as = scores[e[0]], b = e[1], bs = scores[e[1]];
            neighors[b].emplace(as, a); neighors[a].emplace(bs, b);
            if(neighors[a].size() > 3) neighors[a].erase(neighors[a].begin());
            if(neighors[b].size() > 3) neighors[b].erase(neighors[b].begin());
        }
        
        int ans = -1;
        for(const auto& e : edges) {
            int a = e[0], as = scores[e[0]], b = e[1], bs = scores[e[1]];
            for(auto [cs, c] : neighors[a])
                for(auto [ds, d] : neighors[b])
                    if(cs + ds + as + bs > ans && c != d && c != b && a != d)
                        ans = cs + ds + as + bs;
        }
        
        return ans;
        
    }
};