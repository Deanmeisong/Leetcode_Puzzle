class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n);
        dp[0] = prices[0];
        deque<int> dq;
        dq.push_back(0);
        
        for(int i = 1; i < n; ++i) {
            dp[i] = dp[dq.front()] + prices[i];
            while(!dq.empty() && dq.front() + dq.front() + 1 < i) dq.pop_front();
            while(!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        
        return dp[dq.front()];
    }
};