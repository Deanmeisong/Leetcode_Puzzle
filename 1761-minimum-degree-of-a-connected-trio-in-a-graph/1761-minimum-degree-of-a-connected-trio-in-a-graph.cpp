class Solution {
public:
    int connected[401][401];
    int degree[401];
    vector<int> next[401];
    
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        for(auto e : edges) {
            connected[e[0]][e[1]] = 1;
            connected[e[1]][e[0]] = 1;
            degree[e[0]] += 1;
            degree[e[1]] += 1;
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        
        int ret = INT_MAX;
        
        for(int a = 1; a <= n; ++a) {
            for(int i = 0; i < next[a].size(); ++i)
                for(int j = i + 1; j < next[a].size(); ++j) {
                    int b = next[a][i]; int c = next[a][j];
                    if(connected[b][c] == 1) ret = min(ret, degree[a] + degree[b] + degree[c] - 6);
                }
        }
        
        return ret == INT_MAX ? -1 : ret;
    }
};