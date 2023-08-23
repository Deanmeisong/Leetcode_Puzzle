class Solution {
public:
    vector<int> parents;
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        
        int res = 0;
        for(int i = 0; i <= n; ++i) parents.push_back(i);
        for(int i = 0; i < wells.size(); ++i) pq.push({wells[i], 0, i + 1});
        for(vector<int> p : pipes) pq.push({p[2], p[0], p[1]});
        while(n && !pq.empty()) {
            auto[cost, a, b] = pq.top(); pq.pop();
            int pa = find(a), pb = find(b);
            if(pa != pb) {
                parents[pa] = pb;
                res += cost;
                --n;
            }
        }
        
        return res;
    }
    
    int find(int x) {
        while(x != parents[x]) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return parents[x];
    }
};