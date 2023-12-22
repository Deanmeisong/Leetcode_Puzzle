class Solution(object):
    def minimumMoves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        q, seen, target = [(0, 0, 0, 0)], set(), (n - 1, n - 2, 0) 
        for r, c, dr, step in q:
            if(r, c, dr) == target: return step
            if (r, c, dr) not in seen:
                seen.add((r, c, dr))
                if dr:
                    if c + 1 < n and grid[r][c + 1] != 1 and grid[r + 1][c + 1] != 1:
                        q += [(r, c + 1, 1, step + 1), (r, c, 0, step + 1)]
                    if r + 2 < n and grid[r + 2][c] == 0:
                        q += [(r + 1, c, 1, step + 1)]
                else:
                    if r + 1 < n and grid[r + 1][c] != 1 and grid[r + 1][c + 1] != 1:
                        q += [(r + 1, c, 0, step + 1), (r, c, 1, step + 1)]
                    if c + 2 < n and grid[r][c + 2] == 0: 
                        q += [(r, c + 1, 0, step + 1)]
                
        return -1