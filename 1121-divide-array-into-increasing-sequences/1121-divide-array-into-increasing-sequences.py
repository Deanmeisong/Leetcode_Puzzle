class Solution(object):
    def canDivideIntoSubsequences(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        return len(nums) >= k * max(collections.Counter(nums).values())