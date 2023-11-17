class Solution:
    def minimumCosts(self, regular: List[int], express: List[int], expressCost: int) -> List[int]:
        dp1, dp2 = regular[0], expressCost + express[0]
        res = [min(dp1, dp2)]
        n = len(express)
        
        for i in range(1, n):
            dp1t = dp1
            dp1 = min(dp1t + regular[i], dp2 + regular[i])
            dp2 = min(dp2 + express[i], dp1t + express[i] + expressCost)
            res.append(min(dp1, dp2))
            
        return res
        