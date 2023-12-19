class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        # cnt = 0
        # i = len(s) - 1
        # while i >= 0 and not s[i].isalpha():
        #     i = -1
        # while i >= 0 and s[i].isalpha():
        #     i -= 1
        #     cnt += 1
        # return cnt
        cnt = 0
        n = len(s)
        i = n - 1
        while i >= 0 and not s[i].isalpha():
            i -= 1
        while i >= 0 and s[i].isalpha():
            cnt += 1
            i -= 1
        return cnt