class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        auto f = [&](int i, int j) -> long long {
            return (long long) i * n + j;
        };
        
        unordered_set<long long> s;
        unordered_map<int, int> row, col, d1, d2;
        
        for(auto& l : lamps) {
            int i = l[0], j = l[1];
            if(!s.count(f(i, j))) {
                s.insert(f(i, j));
                ++row[i]; ++col[j]; ++d1[i-j]; ++d2[i+j];
            }
        }
        
        int m = queries.size();
        vector<int> ans(m, 0);
        
        for(int k = 0; k < m; ++k) {
            int x = queries[k][0], y = queries[k][1];
            if (row[x] > 0 || col[y] > 0 || d1[x - y] > 0 || d2[x + y] > 0) ans[k] = 1;
            for(int nx = x - 1; nx <= x + 1; ++nx)
                for(int ny = y - 1; ny <= y + 1; ++ny) {
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n || !s.count(f(nx, ny))) continue;
                    s.erase(f(nx, ny));
                    --row[nx]; --col[ny]; --d1[nx-ny]; --d2[nx+ny];
                }
        }
               
        return ans;
    }
};