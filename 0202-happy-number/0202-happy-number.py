class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        dp = set()
        while n not in dp:
            dp.add(n)
            sq = 0
            while n > 0:
                b = n % 10
                sq += b * b
                n //= 10
            if sq == 1: return True
            n = sq
        return False