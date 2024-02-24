using LL = long long;
class Solution {
public:
    LL M = 1e9 + 7;
    vector<pair<int, int>> arr;
    int count0 = 0;
    int countSubMultisets(vector<int>& nums, int l, int r) {
        unordered_map<int, int> Map;
        for(int x : nums) {
            if (x==0) count0++;
            else Map[x]++;
        }
        
        for(auto p : Map) arr.push_back(p);
        arr.insert(arr.begin(), {0, 0});
        return (helper(r) - helper(l-1) + M) % M;
    }
    
    int helper(int limit) {
        if(limit < 0) return 0;
        int m = arr.size() - 1;
        vector<vector<LL>> dp(m + 1, vector<LL>(limit + 1, 0));
        dp[0][0] = 1;
        LL ret = 0;
        for(int i = 1; i <= m; ++i) {
            auto [v, c] = arr[i];
            for(int j = 0; j <= limit; ++j) {
                dp[i][j] = dp[i - 1][j] + (j >= v ? dp[i][j - v] : 0) - (j >= v * (c + 1) ? dp[i - 1][j - v * (c + 1)] : 0);
                dp[i][j] = (dp[i][j] + M) % M;
            }
        }

        for(int j =0; j <= limit; ++j) ret = (ret + dp[m][j]) % M;
        return max(1LL, ret) * (count0+1) % M;
    }
    
};