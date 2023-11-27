using LL = long long;
class Solution {
    LL dp[1005][1005];
    LL M = 1e9 + 7;
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        if(accumulate(nums.begin(), nums.end(), 0LL) < 2 * k) return 0;
        
        nums.insert(nums.begin(), 0);
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; ++i)
            for(int s = 0; s < k; ++s) {
                dp[i][s] += dp[i - 1][s];
                if(s >= nums[i])
                    dp[i][s] += dp[i - 1][s - nums[i]];
                dp[i][s] %= M;
            }
        
        LL total = 1;
        for(int i = 0; i < n; ++i)
            total = total * 2 % M;
        LL invalid = 0;
        for(int s = 0; s < k; ++s)
            invalid = (invalid + dp[n][s]) % M;
        return (total - 2 * invalid + M) % M;
    }
};