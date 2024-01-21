class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size(), m = numSlots;
        nums.insert(nums.begin(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(pow(3, m), INT_MIN/2));
        dp[0][0] = 0;
        int ret = 0;
        
   
        for(int state = 0; state < pow(3, m); ++state) {
            int i = 0;
            int tmp = state;
            while(tmp > 0) {
                i += tmp % 3;
                tmp /= 3;
            }
            if(i > n) continue;
            for(int j = 0; j < m; ++j) {
                if(check(state, j) >= 1) dp[i][state] = max(dp[i][state], dp[i - 1][state - pow(3, j)] + (nums[i] & (j + 1)));
            }
            if(i == n) ret = max(ret, dp[i][state]);            
        }  
        
        
        return ret;

    }
    
    int check(int state, int j) {
        for(int i = 0; i < j; ++i) state /= 3;
        return state % 3;
    }
    
    
    
};