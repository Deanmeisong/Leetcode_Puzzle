class Solution {
public:
    int dp[1005];
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i =0; i < n; ++i) {
            unordered_map<int, int> Map;
            dp[i] = INT_MAX;
            int score = 0;
            for(int j = i; j >= 0; --j) {
                int freq = ++Map[nums[j]];
                if(freq == 2) score += 2;
                if(freq > 2) score += 1;
                if(j >= 1) dp[i] = min(dp[i], score + k + dp[j - 1]);
                else dp[i] = min(dp[i], score + k);
            }
        }
        
        return dp[n - 1];
    }
};