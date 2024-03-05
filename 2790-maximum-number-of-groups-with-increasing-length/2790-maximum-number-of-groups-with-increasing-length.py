class Solution(object):
    def maxIncreasingGroups(self, A):
        """
        :type usageLimits: List[int]
        :rtype: int
        """
        A.sort()
        tt = ans = 0
        for a in A:
            tt += a
            if tt >= (ans+1)*(ans+2)//2:
                ans += 1
        return ans