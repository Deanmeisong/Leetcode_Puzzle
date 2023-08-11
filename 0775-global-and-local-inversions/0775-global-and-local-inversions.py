class Solution:
    def isIdealPermutation(self, nums: List[int]) -> bool:
        for x in range(len(nums)):
            if abs(nums[x] - x) > 1:
                return False
        return True
            