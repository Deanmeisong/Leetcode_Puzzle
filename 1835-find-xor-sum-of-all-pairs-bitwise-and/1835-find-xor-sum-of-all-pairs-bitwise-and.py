class Solution(object):
    def getXORSum(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        ora, orb = 0, 0
        for a in arr1: ora ^= a
        for b in arr2: orb ^= b
        return ora & orb