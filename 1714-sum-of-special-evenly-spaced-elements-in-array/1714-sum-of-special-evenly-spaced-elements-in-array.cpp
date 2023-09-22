class Solution {
public:
    int sums[256][50001];
    long M = 1e9 + 7;
    vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for(int d = 1; d < sqrt(n); ++d)
            for(int i = 0; i < n; ++i)
                sums[d][i] = -1;
        
        vector<int> rets(queries.size());
        for(int k = 0; k < queries.size(); ++k) {
            int s = queries[k][0]; int d = queries[k][1];
            if(d >= sqrt(n)) {
                long total = 0;
                for(int i = s; i < n; i += d) {
                    total = (total + nums[i]) % M;
                }
                rets[k] = total;
            } else {
                if(sums[d][0] == -1) {
                    for(int i = n - 1; i >= 0; --i) {
                        if(i + d < n) {
                            sums[d][i] = (sums[d][i + d] + nums[i]) % M;
                        } else {
                            sums[d][i] = nums[i];
                        }
                    }
                } 
                rets[k] = sums[d][s];
                
            }
        }
        
        return rets;
    }
};