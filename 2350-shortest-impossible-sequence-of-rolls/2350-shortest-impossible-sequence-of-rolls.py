class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        s = set()
        res = 1
        for i in rolls:
            s.add(i)
            if len(s) == k:
                s.clear()
                res += 1
        return res