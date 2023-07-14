class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res, i, seen = 0, 0, [0] * 130
        for j in range(len(s)):
            while seen[ord(s[j])] and i < j:
                seen[ord(s[i])] -= 1
                i += 1
            seen[ord(s[j])] += 1
            length = j - i + 1
            res = max(length, res)
        return res