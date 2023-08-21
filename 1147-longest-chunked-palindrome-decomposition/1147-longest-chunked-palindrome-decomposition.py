class Solution:
    def longestDecomposition(self, s: str) -> int:
        res, n, l, r = 0, len(s), "", ""
        for i in range(n):
            l += s[i]
            r = s[n - i - 1] + r
            if l == r:
                res += 1
                l, r = "", ""
        return res