class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size(); int n = mat[0].size();
        vector<int> sum({0});
        vector<int> sum_tmp;
        for(int i = 0; i < m; ++i) {
            sum_tmp.clear();
            for(int x : mat[i])
                for(int y : sum) {
                    sum_tmp.push_back(x+y);
                }
            sort(sum_tmp.begin(), sum_tmp.end());
            sum_tmp.resize(min(k, (int)sum_tmp.size()));
            swap(sum, sum_tmp);
        }
        return sum[k-1];
    }
};