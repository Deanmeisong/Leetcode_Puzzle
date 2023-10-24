class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n);
        vector<int> presum(n);
        
        for(int i = 0; i < n; ++i) {
            pos[i] = fruits[i][0];
            presum[i] = (i == 0 ? 0 : presum[i - 1]) + fruits[i][1];
        }
        
        int ret = 0;
        
        int m = lower_bound(pos.begin(), pos.end(), startPos) - pos.begin();
        int j = 0;
        for(int i = m; i < n; ++i) {
            while(pos[j] <= startPos && pos[i] - startPos + 2 * (startPos - pos[j]) > k) ++j;
            if(pos[j] <= startPos) ret = max(ret, presum[i] - (j == 0 ? 0 : presum[j - 1]));
            else if(pos[i] - startPos <= k) ret = max(ret, presum[i] - (j == 0 ? 0 : presum[j - 1]));
        }
        j = n - 1;
        m = upper_bound(pos.begin(), pos.end(), startPos) - pos.begin() - 1;
        for(int i = m; i >= 0; --i) {
            while(pos[j] >= startPos && startPos - pos[i] + 2 * (pos[j] - startPos) > k) --j;
            if(pos[j] >= startPos) ret = max(ret, presum[j] - (i == 0 ? 0 :presum[i - 1]));
            else if(startPos - pos[i] <= k) ret = max(ret, presum[j] - (i == 0 ? 0 :presum[i - 1]));
        }
        
        return ret;
    }
};