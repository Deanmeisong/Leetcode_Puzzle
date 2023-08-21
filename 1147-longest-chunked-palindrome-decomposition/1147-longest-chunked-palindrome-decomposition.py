class Solution(object):
    def longestDecomposition(self, s):
        """
        :type text: str
        :rtype: int
        """
        res, n, l, r = 0, len(s), "", ""
        for i in xrange(n):
            l += s[i]
            r = s[n - i - 1] + r
            if l == r:
                res += 1
                l, r = "", ""
        return res