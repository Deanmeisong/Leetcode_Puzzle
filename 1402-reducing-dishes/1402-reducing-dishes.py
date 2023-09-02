class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort(reverse = True);
        res, tmp = 0, 0
        for s in satisfaction:
            if tmp + s <= 0: break
            tmp += s
            res += tmp
        return res