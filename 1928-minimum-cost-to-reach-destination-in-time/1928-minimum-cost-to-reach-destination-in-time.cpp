class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<int>> dp(n, vector<int>(maxTime + 1, INT_MAX / 2));
        vector<int> earliestTime(n + 1, maxTime);
        vector<pair<int, int>> next[1001];
        
        for(auto e : edges) {
            next[e[1]].push_back({e[0], e[2]});
            next[e[0]].push_back({e[1], e[2]});
        }
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        dp[0][0] = passingFees[0];
        
        while(!q.empty()) {
            auto [city, time] = q.front(); q.pop();
            int fee = dp[city][time];
            for(auto [nxt, t] : next[city]) {
                int newFee = fee + passingFees[nxt];
                int newTime = t + time;
                if (newTime > maxTime) continue;
                if(newTime > earliestTime[nxt] && newFee > dp[nxt][earliestTime[nxt]]) continue;
                if(newFee < dp[nxt][newTime]) {
                    dp[nxt][newTime] = newFee;
                    earliestTime[nxt] = min(newTime, earliestTime[nxt]);
                    q.push({nxt, newTime});
                }
                       
            }
      
        }
        
        int ret = INT_MAX / 2;
        for(int t = 0; t <= maxTime; ++t)
            ret = min(ret, dp[n - 1][t]);
        
        if(ret >= INT_MAX / 2) return -1;
        return ret;
    }
};