class Solution:
    def minOperations(self, target: List[int], arr: List[int]) -> int:
        m = {x : i for i, x in enumerate(target)}
        dp = []
        for x in arr:
            if x not in m: continue
            if not dp or m[x] > dp[-1]: dp.append(m[x])
            else: dp[bisect_left(dp, m[x])] = m[x]
        return len(target) - len(dp)