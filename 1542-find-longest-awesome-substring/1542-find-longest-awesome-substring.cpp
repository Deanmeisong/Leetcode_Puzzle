class Solution {
public:
    int longestAwesome(string s) {
        int knf = 1e9 + 7;
        vector<int> masks(1024, knf);
        int m = 0;
        int ans = 0;
        masks[0] = -1;
        
        for(int i = 0; i < s.length(); ++i) {
            m = m ^ (1 << (s[i] - '0'));
            ans = max(ans, i - masks[m]);
            
            for(int j = 0; j < 10; ++j) {
                ans = max(ans, i - masks[m ^ (1 << j)]);
            }
                          
            masks[m] = min(i, masks[m]);
        }
        
        return ans;
    }
};