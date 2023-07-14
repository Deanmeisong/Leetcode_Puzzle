class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(130);
        int res = 0, i = 0;
        for(int j = 0; j < s.length(); ++j) {
            while(seen[s[j]] and i < j) {
                --seen[s[i++]];
            }
            ++seen[s[j]];
            int len = j - i + 1;
            res = max(len, res);
        }
        return res;
    }
};