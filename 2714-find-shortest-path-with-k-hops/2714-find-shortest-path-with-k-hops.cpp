using ti3 = tuple<int,int,int>;
class Solution {
public:
    int shortestPathWithHops(int n, vector<vector<int>>& edges, int s, int d, int k) {
        vector<pair<int,int>> g[n];
        for(auto e : edges) {
            int a = e[0], b = e[1], w = e[2];
            g[a].emplace_back(b, w);
            g[b].emplace_back(a, w);
        }
        priority_queue<ti3, vector<ti3>, greater<ti3>> pq;
        pq.emplace(0, s, 0);
        
        int dist[n][k+1];
        memset(dist, 0x3f, sizeof(dist));
        dist[s][0] = 0;
        while(!pq.empty()) {
            auto [dis, u, t] = pq.top(); pq.pop();
            for(auto [v, w] : g[u]) {
                if(t + 1 <= k && dist[v][t+1] > dis) {
                    dist[v][t+1] = dis;
                    pq.emplace(dis, v, t+1);
                }
                if(dist[v][t] > dis + w) {
                    dist[v][t] = dis + w;
                    pq.emplace(dis+w, v, t);
                }
            }
        }
        return *min_element(dist[d], dist[d] + k + 1);

    }
};