class Solution(object):
    def maxSatisfaction(self, satisfaction):
        """
        :type satisfaction: List[int]
        :rtype: int
        """
        satisfaction.sort(reverse = True);
        res, tmp = 0, 0
        for s in satisfaction:
            if tmp + s <= 0: break
            tmp += s
            res += tmp
        return res