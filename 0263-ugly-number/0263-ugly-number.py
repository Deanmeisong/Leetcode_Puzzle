class Solution(object):
    def isUgly(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n == 0: return False
        ps = {2, 3, 5}
        for p in ps:
            while n % p == 0: n //= p
        return n == 1