class Solution:
    def countSubranges(self, nums1: List[int], nums2: List[int]) -> int:
        M = (int)(1e9 + 7)
        N = len(nums1)
        DP = [defaultdict(int) for _ in range(N + 1)]
        ans = 0
        
        for i in range(1, N + 1):
            n1 = nums1[i - 1]
            n2 = nums2[i - 1]
            DP[i][n1] += 1
            DP[i][-n2] += 1
            for (key, value) in DP[i - 1].items():
                DP[i][key + n1] = (DP[i][key + n1] + value) % M
                DP[i][key - n2] = (DP[i][key - n2] + value) % M
            ans = (ans + DP[i][0]) % M
            
        return ans
        