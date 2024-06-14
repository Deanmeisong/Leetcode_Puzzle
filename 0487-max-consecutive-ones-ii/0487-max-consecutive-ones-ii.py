class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans = dp0 = dp1 = 0
        for x in nums:
            if x == 1:
                dp0 += 1
                dp1 += 1
            else:
                dp1 = dp0 + 1
                dp0 = 0
            ans = max(ans, dp1)
        return ans;