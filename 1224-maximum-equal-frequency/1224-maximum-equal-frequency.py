class Solution(object):
    def maxEqualFreq(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = [0] * 100001
        freq = [0] * 100001
        n = len(nums)
        
        for num in nums:
            count[num] += 1
            freq[count[num]] += 1
            
        for i in range(n - 1, 0, -1):
            if count[nums[i]] * freq[count[nums[i]]] == i:
                return i + 1
            freq[count[nums[i]]] -= 1
            count[nums[i]] -= 1
            if count[nums[i - 1]] * freq[count[nums[i - 1]]] == i:
                return i + 1
        return 1