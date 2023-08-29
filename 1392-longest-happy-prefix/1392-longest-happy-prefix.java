class Solution {
    public String longestPrefix(String s) {
        char[] cs = s.toCharArray();
        long l = 0, r = 0, b = 1, mod = 1000000007; int len = 0; int n = s.length();
        for(int i = 0; i < n - 1; ++i) {
            l = (l * 128 + cs[i]) % mod;
            r = (cs[n - i - 1] * b + r) % mod;
            b = b * 128 % mod;
            if(l == r) len = i + 1;
        }
        return s.substring(0, len);
    }
}