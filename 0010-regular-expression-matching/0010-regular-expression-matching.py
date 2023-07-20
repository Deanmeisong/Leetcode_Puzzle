class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[False for _ in range(len(s) + 1)]
              for _ in range(len(p) + 1)
             ]
        
        dp[0][0] = True
        
        for x in range(1, len(p) + 1):
            if p[x - 1] == '*':
                dp[x][0] = dp[x - 2][0]
                
        for s1 in range(1, len(s) + 1):
            for p1 in range(1, len(p) + 1):
                if p[p1 - 1] == '.' or p[p1- 1] == s[s1 - 1]:
                    dp[p1][s1] = dp[p1 - 1][s1 - 1]
                if p[p1 - 1] == '*':
                    if s[s1 - 1] == p[p1 - 2] or p[p1 - 2] == '.':
                        dp[p1][s1] = dp[p1 - 2][s1] or dp[p1][s1 - 1]
                    else:
                        dp[p1][s1] = dp[p1 - 2][s1]
        
        print(dp)
            
        return dp[len(p)][len(s)]
        
        
        
        
        