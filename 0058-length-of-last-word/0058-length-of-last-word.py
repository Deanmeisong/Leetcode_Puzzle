class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        cnt = 0
        n = len(s)
        i = n - 1
        while i >= 0 and not s[i].isalpha():
            i -= 1
        while i >= 0 and s[i].isalpha():
            cnt += 1
            i -= 1
        return cnt