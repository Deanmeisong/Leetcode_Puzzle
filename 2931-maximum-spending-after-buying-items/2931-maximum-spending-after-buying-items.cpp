class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        int m = values.size(), n = values[0].size();
        for(int i = 0; i < m; ++i) pq.push({values[i][n - 1], i, n - 1});
        long long ans = 0;
        for(int d = 1; pq.size(); ++d) {
            auto[v, i, j] = pq.top(); pq.pop();
            ans += 1LL * v * d;
            if(j >= 1) pq.push({values[i][j - 1], i, j - 1});
        }
        return ans;
    }
};