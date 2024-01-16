class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for j in range(32):
            b = 0
            for i in range(n):
                b += (nums[i] >> j) & 1
            ans += b * (n - b)
        
        return ans