class Solution {
public:
    static bool compare(vector<int>& e1, vector<int>& e2) {
        return e1[1] < e2[1];
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        int m = events.size();
        sort(events.begin(), events.end(), compare);
        auto dp = vector<vector<int>>(m + 1, vector<int>(k + 1));
        events.insert(events.begin(), events[0]);
        vector<int> endTimes({0});
        for(int i = 1; i <= m; ++i) dp[i][0] = 0;
        int ans = 0;
        for(int i = 1; i <= m; ++i) {
            int t = lower_bound(endTimes.begin(), endTimes.end(), events[i][0]) - 1 - endTimes.begin();
            for(int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[t][j - 1] + events[i][2]);
                
            }
            endTimes.push_back(events[i][1]);
        }
        
        for(int i = 1; i <= k; ++i)
            ans = max(ans, dp[m][i]);
        return ans;
    }
};