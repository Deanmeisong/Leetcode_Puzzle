class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<long> dp((1 << n), 0);
        long mod = 1e9 + 7;
        dp[0] = 1;
        
        map<int, vector<int>> personsForHat;
        for(int i = 0; i < hats.size(); ++i) {
            for(int h : hats[i]) personsForHat[h].push_back(i);
        }
        
        for(int hat = 1; hat <= 40; ++hat) {
            auto dp_new = dp;
            for(int state = 0; state < (1 << n); ++state) {
                for(int p : personsForHat[hat]) {
                    if (((state>>p)&1)==1)
                        continue;
                    dp_new[state + (1 << p)] += dp[state];
                    dp_new[state + (1 << p)] %= mod;
                } 
            }
            dp = dp_new;
        }
        
        return dp[(1<<n) - 1] % mod;
    }
};