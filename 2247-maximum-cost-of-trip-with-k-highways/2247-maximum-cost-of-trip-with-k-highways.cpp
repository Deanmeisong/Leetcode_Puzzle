class Solution {
public:
    int maximumCost(int n, vector<vector<int>>& highways, int k) {
        vector<bool> visited(n, false);
        priority_queue<tuple<int, int, pair<int, int>>> pq; // cost, node, kth, parent
        vector<vector<array<int, 2>>> adj(n);
        for(const auto& h : highways) {
            adj[h[0]].push_back({h[1], h[2]});
            adj[h[1]].push_back({h[0], h[2]});
        }
        
        int ret = -1;
        
        for(int node = 0; node < n; ++node) {
            fill(visited.begin(), visited.end(), false);
            pq.push(make_tuple(0, node, make_pair(0, -1)));
            while(!pq.empty()) {
                tuple<int, int, pair<int, int>> t = pq.top(); pq.pop();
                int cur = get<1>(t);
                int cost = get<0>(t);
                int kth = get<2>(t).first;
                int parent = get<2>(t).second;
                visited[cur] = true;
                
                if(kth == k) {
                    ret = max(ret, cost);
                    break;
                }
                
                for(auto [nxt, cost2] : adj[cur]) 
                    if(visited[nxt] == false) pq.push(make_tuple(cost + cost2, nxt, make_pair(kth + 1, cur)));
                
            }
            
            while(!pq.empty()) {
                pq.pop();
            }
        }
        
        return ret < 0 ? -1 : ret;
    }
};