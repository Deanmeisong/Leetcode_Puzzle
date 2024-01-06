class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
        ora, orb = 0, 0
        for a in arr1: ora ^= a
        for b in arr2: orb ^= b
        return ora & orb