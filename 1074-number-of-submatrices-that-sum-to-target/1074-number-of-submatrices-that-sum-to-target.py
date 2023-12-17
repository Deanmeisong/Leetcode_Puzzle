class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            vector<int> row(n);
            for(int j = i; j < m; ++j) {
                for(int k = 0; k < n; ++k) row[k] += matrix[j][k];
                unordered_map<int, int> Map;
                Map[0] = 1;
                int presum = 0;
                for(int k = 0; k < n; ++k) {
                    presum += row[k];
                    cnt += Map[presum - target];
                    ++Map[presum];
                }
            }
        }
        return cnt;
    }
};