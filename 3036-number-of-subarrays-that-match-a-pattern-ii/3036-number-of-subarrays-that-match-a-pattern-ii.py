class Solution(object):
    def countMatchingSubarrays(self, nums, pattern):
        """
        :type nums: List[int]
        :type pattern: List[int]
        :rtype: int
        """
        def lcs(s):
            n = len(s)
            dp = [0]*n
            for i in range(1, n):
                j = dp[i-1]
                while j > 0 and s[i] != s[j]:
                    j = dp[j - 1]
                dp[i] = j + (s[i] == s[j])
            return dp
        
        arr = map(cmp, nums[1:], nums[:-1])
        ns = lcs(pattern + [256] + arr)
        return ns.count(len(pattern))