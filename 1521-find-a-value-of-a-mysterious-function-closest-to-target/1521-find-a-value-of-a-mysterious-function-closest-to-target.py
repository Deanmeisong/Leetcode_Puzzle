class Solution:
    def closestToTarget(self, arr: List[int], target: int) -> int:
        s = set()
        res = float('inf')
        for i in range(len(arr)):
            s1 = set()
            for x in s:
                s1.add(x & arr[i])
            s1.add(arr[i])
            for x in s1:
                res = min(res, abs(x - target))
            s = s1
        return res