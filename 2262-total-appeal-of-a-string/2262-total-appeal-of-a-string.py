class Solution(object):
    def appealSum(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        n = len(s)
        last = [-1] * 26
        
        for i in range(n):
            j = last[ord(s[i]) - ord('a')]
            ans += (i - j) * (n - i)
            last[ord(s[i]) - ord('a')] = i
        
        return ans