class Solution:
    def confusingNumberII(self, n: int) -> int:
        valid = [0, 1, 6, 8, 9]
        mapping = {0:0, 1:1, 6:9, 9:6, 8:8}
        self.count = 0;
        
        def bt(v, rt, d):
            if v:
                if v != rt:
                    self.count += 1
            for i in valid:
                if v*10 + i > n:
                    break
                else:
                    bt(v*10 + i, mapping[i]*d + rt, d*10)
        
        bt(1, 1, 10)
        bt(6, 9, 10)
        bt(9, 6, 10)
        bt(8, 8, 10)
        
        return self.count
        