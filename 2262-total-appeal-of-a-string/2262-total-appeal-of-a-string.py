class Solution:
    def appealSum(self, s: str) -> int:
        ans = 0
        n = len(s)
        last = [-1] * 26
        
        for i in range(n):
            j = last[ord(s[i]) - ord('a')]
            ans += (i - j) * (n - i)
            last[ord(s[i]) - ord('a')] = i
        
        return ans