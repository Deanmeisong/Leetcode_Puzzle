class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0; int n = s.length();
        vector<int> last(26, -1);
        for(int i = 0; i < n; ++i) {
            int j = last[s[i] - 'a'];
            ans += (long long)(i - j) * (long long)(n - i);
            last[s[i] - 'a'] = i;
        }
        return ans;
    }
};