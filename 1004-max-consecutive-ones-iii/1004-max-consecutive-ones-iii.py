class Solution(object):
    def longestOnes(self, nums, k):
        l, r, c, ans, n = 0, 0, 0, 0, len(nums)
        while r < n:
            if nums[r] == 0: c += 1
            while c > k:
                if nums[l] == 0: c -= 1
                l += 1
            ans = max(ans, r - l + 1)
            r += 1
        return ans