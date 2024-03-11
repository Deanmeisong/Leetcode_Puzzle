using LL = long long;
class Solution {
public:
    vector<vector<vector<LL>>> dp;
    LL dfs(int i, LL k, bool started, vector<int>& nums) {
        if(k == 0) return 0;
        if(i == nums.size()) {
            if(k == 1 && started) return 0;
            return -1e15;
        }
        if(dp[i][k][started] != -1e16) return dp[i][k][started];
        LL ret = -1e15;
        if(started) ret = max(ret,dfs(i, k-1, false, nums));
        LL cur = k * ((k%2 == 1) ? 1 : -1) * nums[i];
        ret = max(ret, cur + dfs(i+1, k, true, nums));
        if(!started) ret = max(ret, dfs(i+1, k, false, nums));
        return dp[i][k][started] = ret;
        
    }
    long long maximumStrength(vector<int>& nums, int k) {
        dp = vector<vector<vector<LL>>>(nums.size(), vector<vector<LL>>(k+1, vector<LL>(2, -1e16)));
        return dfs(0, (LL)k, false, nums);
    }
};