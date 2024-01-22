class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = []
        
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a
        
        def lcm(x, y):
            return (x * y) // gcd(x, y)
        
        for x in nums:
            while res and gcd(res[-1], x) > 1:
                x = lcm(res[-1], x)
                res.pop()
            res.append(x)
        return res