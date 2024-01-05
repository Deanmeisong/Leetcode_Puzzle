class Solution(object):
    def maxNiceDivisors(self, x):
        """
        :type primeFactors: int
        :rtype: int
        """
        if x == 1: return 1
        if x == 2: return 2
        if x == 3: return 3
        
        m = 10**9 + 7
        a, b = x / 3, x % 3
        if b == 0: return pow(3, a, m);
        if b == 1: return pow(3, a - 1, m) * 4 % m
        if b == 2: return pow(3, a, m) * 2 % m
