class Solution(object):
    def maximizeSweetness(self, sweetness, k):
        """
        :type sweetness: List[int]
        :type k: int
        :rtype: int
        """
        def ok(S):
            cnt, amount = 0, 0
            for x in sweetness:
                amount += x
                if amount >= S:
                    cnt += 1
                    amount = 0
            return cnt >= k + 1
        
        l, r = 0, sum(sweetness)
        while l < r:
            m = (r - l + 1) / 2 + l
            if ok(m): l = m
            else: r = m - 1
        return l