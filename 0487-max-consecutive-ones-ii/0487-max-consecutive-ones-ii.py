class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = l = r = num0 = 0
        while r < len(nums):
            if nums[r] == 0:
                num0 += 1
            while num0 == 2:
                if nums[l] == 0:
                    num0 -= 1
                l += 1
            ans = max(ans, r - l + 1)
            r += 1
        return ans