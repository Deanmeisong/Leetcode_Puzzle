class Solution(object):
    def minimumTimeRequired(self, jobs, k):
        """
        :type jobs: List[int]
        :type k: int
        :rtype: int
        """
        n = len(jobs)
        self.res = sum(jobs)
        count = [0] * k
        jobs.sort(reverse = True)
        
        def dfs(cur):
            if cur == len(jobs): 
                self.res = min(self.res, max(count))
                return
            
            for i in range(k):
                if count[i] + jobs[cur] >= self.res: continue
                count[i] += jobs[cur]
                dfs(cur + 1)
                count[i] -= jobs[cur]
                if count[i] == 0: break
        dfs(0)
        return self.res