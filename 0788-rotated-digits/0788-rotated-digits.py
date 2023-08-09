class Solution:
    def rotatedDigits(self, n):
        ans = 0
        for i in range(n+1):
            if self.helper(i):
                ans += 1
        return ans
    
    def helper(self, x):
        flag = False
        while x > 0:
            t = x % 10
            x //= 10
            if t == 4 or t == 3 or t == 7:
                return False
            if t == 6 or t == 9 or t == 2 or t == 5:
                flag = True
        return flag