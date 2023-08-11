class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if n == 1: return 0
        if k > (1 << (n - 2)): return 1 ^ self.kthGrammar(n - 1, k - (1 << (n - 2)))
        else: return self.kthGrammar(n - 1, k)