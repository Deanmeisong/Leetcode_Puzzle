class Solution:
    def minMovesToMakePalindrome(self, S: str) -> int:
        ret, n, count = 0, len(S), 0
        s = list(S)
        i = 0
        while i < n // 2:
            j = n - 1 - count
            while s[i] != s[j]:
                j -= 1
            
            if i == j:
                ret += n // 2 - i
            else:
                k = n - count - 1 - j
                ret += k
                count += 1

                for _ in range(k):
                    tmp = s[j]
                    s[j] = s[j + 1]
                    s[j + 1] = tmp
                    j += 1

            i += 1

        return ret