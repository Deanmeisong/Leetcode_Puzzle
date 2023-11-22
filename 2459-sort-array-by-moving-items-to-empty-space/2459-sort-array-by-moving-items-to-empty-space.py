class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        pos = [0] * n
        for i, k in enumerate(nums): pos[k] = i;
        
        def helper(pos, s):
            cnt, nxt = 0, 1
            while nxt < n:
                if pos[0] == s * (n - 1):
                    while pos[nxt] == nxt - s:
                        nxt += 1
                        if nxt == n:
                            return cnt
                    ni = nxt
                else: ni = pos[0] + s
                
                pos[0], pos[ni] = pos[ni], pos[0]
                cnt += 1
     
        
        return min(helper(list(pos), 1), helper(list(pos), 0))