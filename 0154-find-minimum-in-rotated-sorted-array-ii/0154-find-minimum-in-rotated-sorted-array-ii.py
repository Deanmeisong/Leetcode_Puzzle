class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # l, r = 0, len(nums) - 1
        l = 0
        r = len(nums) - 1
        # while l < r and nums[l] == nums[r]: l += 1
        while l < r and nums[l] == nums[r]:
            l += 1
        while l < r:
            m = (r - l) // 2 + l
            if nums[m] > nums[r]:
                l = m + 1
            else:
                r = m
        return nums[r]
    