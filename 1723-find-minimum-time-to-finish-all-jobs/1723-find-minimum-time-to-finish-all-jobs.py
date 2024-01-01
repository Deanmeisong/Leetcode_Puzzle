class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        works = [0] * k
        self.res = sys.maxsize
        def dfs(cur):
            if cur == len(jobs):
                self.res = min(self.res, max(works))
                return
            seen = set()
            for x in range(k):
                if works[x] in seen: continue
                if works[x] + jobs[cur] >= self.res: continue
                seen.add(works[x])
                works[x] += jobs[cur]
                dfs(cur + 1)
                works[x] -= jobs[cur]
        
        dfs(0)
        return self.res
                