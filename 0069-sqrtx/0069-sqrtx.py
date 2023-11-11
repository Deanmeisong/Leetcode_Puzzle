class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 1: return 1
        l, r = 1, x
        while l < r:
            m = (r - l) // 2 + l
            if m > x // m: r = m
            else: l = m + 1
        return l - 1