class Solution {
public:
    int longestDecomposition(string s) {
        int res = 0; int n = s.length();
        string l = ""; string r = "";
        for(int i = 0; i < n; ++i) {
            l += s[i]; r = s[n - i - 1] + r;
            if(l == r) {
                res++;
                l = "";
                r = "";
            }
        }
        return res;
    }
};