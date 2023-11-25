using AI3 = array<int, 3>;
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int n = queries.size();
        vector<int> ret(n);
        vector<pair<int, int>> qs;
        for(int i = 0; i < n; ++i) qs.push_back({queries[i], i});
        sort(qs.begin(), qs.end());
        priority_queue<AI3, vector<AI3>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        visited[0][0] = 1;
        int count = 0;
        
        
        for(auto [q, idx]: qs) {
            
            while(!pq.empty() && pq.top()[0] < q) {
                int i = pq.top()[1]; int j =pq.top()[2];
                pq.pop();
                ++count;
                for(int k = 0; k < 4; ++k) {
                    int x = i + dir[k][0]; int y = j + dir[k][1];
                    if(x < 0 || x > grid.size() - 1 || y < 0 || y > grid[0].size() - 1) continue;
                    if(visited[x][y]) continue;
                    pq.push({grid[x][y],x,y});
                    visited[x][y] = 1;
                }
            }
            ret[idx] = count;

        }
        
        return ret;
        
               
    }
};