class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        vector<int> dp(1<<m, INT_MAX/2);
        vector<int> dp2(1<<m);
        dp[0] = 0;
        
        for(int j = 0; j < m; ++j) {
            dp2 = dp;
            int k = j + 1;
            int state = (1<<k) - 1;
            dp[state] = INT_MAX/2;
            
            while(state < (1<<m)) {
                for(int i = 0; i < m; ++i) {
                    if((state>>i)&1)
                        dp[state] = min(dp[state], dp2[state - (1<<i)] + (nums1[j]^nums2[i]));
                }
                int lowBit = state & (-state);
                int left = state + lowBit;
                state = (((left ^ state) >> 2) / lowBit) | left;
            }
            
        }
        
        return dp[(1<<m) - 1];
    }
};