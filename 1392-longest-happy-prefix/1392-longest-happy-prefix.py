class Solution(object):
    def longestPrefix(self, s):
        """
        :type s: str
        :rtype: str
        """
        l, r, b, k, mod = 0, 0, 1, 0, 10**9 + 7
        for i in range(0, len(s) - 1):
            l = (l * 128 + ord(s[i])) % mod
            r = (ord(s[~i]) * b + r) % mod
            b = b * 128 % mod
            if l == r: k = i + 1
        return s[:k]