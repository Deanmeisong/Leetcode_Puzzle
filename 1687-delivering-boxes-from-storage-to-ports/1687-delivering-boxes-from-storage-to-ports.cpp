class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size();
        boxes.insert(boxes.begin(), {-1, 0});
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        
        int ws = 0, ts = 0, j = 0, lp = -1, lpIdx;
        for(int i = 1; i <= n; ++i) {
            while(j + 1 <= n && j + 1 - i + 1 <= maxBoxes && ws + boxes[j + 1][1] <= maxWeight) {
                j += 1;
                ws += boxes[j][1];
                if(boxes[j - 1][0] != boxes[j][0]) ts += 1;
                if(lp != boxes[j][0]) {
                    lp = boxes[j][0];
                    lpIdx = j;
                }
            }
            
            dp[j] = min(dp[j], dp[i - 1] + ts + 1);
            if(j + 1 <= n && boxes[j + 1][0] == boxes[j][0])
                dp[lpIdx - 1] = min(dp[lpIdx - 1], dp[i - 1] + ts);
            ws -= boxes[i][1];
            ts -= (i + 1 <= n && boxes[i][0] != boxes[i + 1][0]);
        }
        
        return dp[n];
    }
};