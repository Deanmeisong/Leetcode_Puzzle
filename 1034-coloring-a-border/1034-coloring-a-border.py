class Solution(object):
    def colorBorder(self, grid, row, col, color):
        m, n, seen = len(grid), len(grid[0]), set()
        def dfs(x, y):
            if (x, y) in seen: return True
            if not (0 <= x < m and 0 <= y < n and grid[x][y] == grid[row][col]): return False
            seen.add((x, y))
            if dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1) < 4: grid[x][y] = color
            return True
        dfs(row, col)
        return grid