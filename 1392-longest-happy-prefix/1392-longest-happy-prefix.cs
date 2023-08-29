public class Solution {
    public string LongestPrefix(string s) {
        int mod = 1000000007;
        long l = 0, r = 0, p = 1; int n = s.Length, len = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            l = (l * 128 + s[i]) % mod;
            r = (r + p * s[n - i - 1]) % mod;
            if (l == r) len = i + 1;
            p = p * 128 % mod;
        }
        return s.Substring(0, (int)len);

    }
}