class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        i = 0
        ans = 0
        n = len(s)
        
        for j in range(n):
            maxCost -= abs(ord(s[j]) - ord(t[j]))  # Calculate the cost for the current character
            while maxCost < 0 and i <= j and i < n:  # If the cost exceeds maxCost, move the start index
                maxCost += abs(ord(s[i]) - ord(t[i]))
                i += 1
            ans = max(ans, j - i + 1)  # Calculate the maximum length of substring within the maxCost
        
        return ans