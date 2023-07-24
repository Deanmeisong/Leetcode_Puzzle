class Solution:
    def romanToInt(self, s: str) -> int:
        romans = ['M', 'D', 'C', 'L', 'X', 'V', 'I']
        ints = [1000, 500, 100, 50, 10, 5, 1]
        m = {}
        for i in range(len(romans)):
            m[romans[i]] = ints[i]
        ans = 0
        for i in range(len(s)):
            if i < len(s) - 1:
                if m[s[i]] >= m[s[i + 1]]:
                    ans += m[s[i]]
                else:
                    ans -= m[s[i]]
            else:
                ans += m[s[i]]
        return ans