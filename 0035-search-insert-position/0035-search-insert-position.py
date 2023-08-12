class Solution:
    def searchInsert(self, nums: List[int], t: int) -> int:
        l, m, r = 0, 0, len(nums) - 1
        while l <= r:
            m = (r - l) // 2 + l;
            if nums[m] == t: return m
            if nums[m] > t: r = m - 1
            else: l = m + 1
        return l