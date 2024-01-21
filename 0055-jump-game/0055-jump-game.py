class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        if n == 1: return True
        far = 0
        for i in range(n):
            far = max(far, i + nums[i])
            if i >= far and i != n - 1: return False;
            if far >= n - 1: return True
        
        return True