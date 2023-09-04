class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.presum = nums;
        for i in range(len(self.presum) - 1):
            self.presum[i + 1] += self.presum[i]

    def sumRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        if left == 0: return self.presum[right]
        return self.presum[right] - self.presum[left - 1]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)