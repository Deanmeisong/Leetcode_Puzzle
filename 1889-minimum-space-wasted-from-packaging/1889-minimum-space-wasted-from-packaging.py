class Solution(object):
    def minWastedSpace(self, packages, boxes):
        """
        :type packages: List[int]
        :type boxes: List[List[int]]
        :rtype: int
        """
        packages.sort()
        res = float('inf')
        
        for b in boxes:
            b.sort()
            if b[-1] < packages[-1]: continue
            cur = i = 0
            for b1 in b:
                j = bisect.bisect(packages, b1, i)
                cur += (j - i) * b1
                i = j
            res = min(res, cur)
        
        return (res - sum(packages)) % (10 ** 9 + 7) if res < float('inf') else -1