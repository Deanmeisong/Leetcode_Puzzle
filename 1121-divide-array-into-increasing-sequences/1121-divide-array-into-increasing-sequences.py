class Solution:
    def canDivideIntoSubsequences(self, nums: List[int], k: int) -> bool:
        return len(nums) >= k * max(collections.Counter(nums).values())