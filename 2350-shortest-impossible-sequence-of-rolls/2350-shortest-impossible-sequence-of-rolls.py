class Solution(object):
    def shortestSequence(self, rolls, k):
        """
        :type rolls: List[int]
        :type k: int
        :rtype: int
        """
        s = set()
        res = 1
        for i in rolls:
            s.add(i)
            if len(s) == k:
                s.clear()
                res += 1
        return res