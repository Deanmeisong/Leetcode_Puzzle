class Solution(object):
    def maxNiceDivisors(self, x):
        """
        :type primeFactors: int
        :rtype: int
        """
        if x <= 3: return x
        
        m = 10**9 + 7
        if x % 3 == 0: return pow(3, x // 3, m)
        if x % 3 == 1: return pow(3, (x - 4) // 3, m) * 4 % m
        if x % 3 == 2: return pow(3, x // 3, m) * 2 % m
