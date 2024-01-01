class Solution(object):
    def minimumTimeRequired(self, jobs, k):
        """
        :type jobs: List[int]
        :type k: int
        :rtype: int
        """
        self.res = sys.maxsize
        count = [0] * k
        
        def dfs(cur):
            if cur == len(jobs): 
                self.res = min(self.res, max(count))
                return
            
            seen = set()
            for i in range(k):
                if count[i] in seen: continue
                if count[i] + jobs[cur] >= self.res: continue
                seen.add(count[i])
                count[i] += jobs[cur]
                dfs(cur + 1)
                count[i] -= jobs[cur]
        
        dfs(0)
        return self.res