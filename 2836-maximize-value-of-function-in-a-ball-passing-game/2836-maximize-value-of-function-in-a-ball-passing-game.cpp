using LL = long long;
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        int m = ceil(log(k)/log(2));
        vector<vector<LL>> dp(n + 1, vector<LL>(m + 1));
        vector<vector<LL>> pos(n + 1, vector<LL>(m + 1));
        for(int i = 0; i < n; ++i) {
            dp[i][0] = receiver[i];
            pos[i][0] = receiver[i];
        }
        for(int j = 1; j <= m; ++j)
            for(int i = 0; i < n; ++i) {
                pos[i][j] = pos[pos[i][j-1]][j-1];
                dp[i][j] = dp[i][j-1] + dp[pos[i][j-1]][j-1];
            }
        vector<int> bits;
        for(int i = 0; i <= m; ++i)
            if((k>>i)&1) bits.push_back(i);
        LL ret = 0;
        for(int i = 0; i < n; ++i) {
            LL val = i;
            int cur = i;
            for(int j : bits) {
                val += dp[cur][j];
                cur = pos[cur][j];
            }
            ret = max(ret, val);
        }
        return ret;
    }
};