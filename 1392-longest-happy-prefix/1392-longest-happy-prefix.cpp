class Solution {
public:
    int mod = 1e9 + 7;
    string longestPrefix(string s) {
        long l = 0, r = 0, p = 1, n = s.length(), len = 0;

        for(int i = 0; i < n - 1; ++i) {
            // l = ((s[i] - 'a')  + l * 26) % kMod;
            // r = ((s[n - i - 1] - 'a') * b + r) % kMod;
            // b = b * 26 % kMod;
            // if(l == r) len = i + 1;
            l = (l * 128 + s[i]) % mod;
            r = (r + p * s[n-i-1]) % mod;
            if (l == r) len = i + 1;
            p = p * 128 % mod;
        }
        
        return s.substr(0, len);
        
    }
};