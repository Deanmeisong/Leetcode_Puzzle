class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        count, freq = [0] * 100001, [0] * 100001
        for num in nums:
            count[num] += 1
            freq[count[num]] += 1
        n = len(nums)
        for i in range(n - 1, 0, -1):
            if freq[count[nums[i]]] * count[nums[i]] == i: return i + 1
            freq[count[nums[i]]] -= 1
            count[nums[i]] -= 1
            if freq[count[nums[i - 1]]] * count[nums[i - 1]] == i: return i + 1
        return 1