class Solution(object):
    def largestVariance(self, s):
        """
        :type s: str
        :rtype: int
        """
        cs = set(s)
        n = len(s)
        ret = 0
        
        for a in cs:
            for b in cs:
                if a == b: continue
                dpa, dpb = 0, float('-inf') // 2
                for i in range(n):
                    if s[i] == a:
                        dpa += 1
                        dpb += 1
                    elif s[i] == b:
                        dpb = max(dpa - 1, dpb - 1)
                        dpa = 0
                    ret = max(ret, dpb)
        return ret