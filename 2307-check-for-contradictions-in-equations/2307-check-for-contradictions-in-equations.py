class Solution(object):
    def checkContradictions(self, equations, values):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :rtype: bool
        """
        weights = defaultdict(lambda: defaultdict(lambda: 1))
        uf = {}
        def find(x):
            uf.setdefault(x,x)
            if uf[x]!=x:
                y = find(uf[x])
                weights[x][y] = weights[x][uf[x]]*weights[uf[x]][y]
                uf[x]=y
            return uf[x]
        def tryUnion(x,y,w):
            xp,yp = find(x),find(y)
            if xp==yp:
                expected = weights[x][xp]*(1/weights[y][yp])
                return abs(w-expected)>10**-6
            uf[xp] = yp
            weights[xp][yp] = w*weights[y][yp]*(1/weights[x][xp])
            return False
        return any(tryUnion(b,a,v) for (a,b),v in zip(equations,values))
        