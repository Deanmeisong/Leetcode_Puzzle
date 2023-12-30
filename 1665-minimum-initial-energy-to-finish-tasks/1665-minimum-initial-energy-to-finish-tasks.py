class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[1] - x[0])
        ret = 0
        for t in tasks:
            ret = max(ret + t[0], t[1])
        return ret