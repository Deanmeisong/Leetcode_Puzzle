class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        q = [start];
        dirs = ((0, 1), (0, -1), (1, 0), (-1, 0))
        m, n = len(maze), len(maze[0])
        while q:
            r, c = q.pop()
            maze[r][c] = 2
            if destination[0] == r and destination[1] == c:
                return True
            for i in range(4):
                x, y = dirs[i]
                nr, nc = r + x, c + y
                while 0 <= nr < m and 0 <= nc < n and maze[nr][nc] != 1:
                    nr += x
                    nc += y
                nr -= x
                nc -= y
                if maze[nr][nc] == 0:
                    q.append([nr, nc])

        return False