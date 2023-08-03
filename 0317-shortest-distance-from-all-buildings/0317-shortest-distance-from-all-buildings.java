class Solution {
    private int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public int shortestDistance(int[][] grid) {
//               if (grid == null || grid.length == 0) return -1;
//         int rows = grid.length, cols = grid[0].length;
//         int[][] canReach = new int[rows][cols];
//         int[][] dist = new int[rows][cols];
        
//         int totalBuildings = 0;
//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 if (grid[i][j] == 1) {
//                     totalBuildings++;
//                     if (!bfs(i, j, grid, canReach, dist)) return -1;
//                 }
//             }
//         }
        
//         int minDis = Integer.MAX_VALUE;
//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 if (canReach[i][j] == totalBuildings &&
//                    dist[i][j] < minDis) {
//                     minDis = dist[i][j];
//                 }
//             }
//         }
        
//         return minDis == Integer.MAX_VALUE ? -1 : minDis;
        if(grid == null || grid.length == 0) return -1;
        int m = grid.length; int n = grid[0].length;
        int[][] canReach = new int[m][n];
        int[][] dist = new int[m][n];
        int total = 0;
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    ++total;
                    if(!bfs(i, j, grid, canReach, dist)) return -1;
                }
            }
        
        int minD = Integer.MAX_VALUE;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(canReach[i][j] == total) {
                    if(dist[i][j] < minD) minD = dist[i][j];
                }
            }
        
        return minD == Integer.MAX_VALUE ? -1 : minD;
    }
    
    public boolean bfs(int x, int y, int[][] grid, int[][] canReach, int[][] dist) {
//         int rows = grid.length, cols = grid[0].length;
//         boolean[][] visited = new boolean[rows][cols];
        
//         Queue<int[]> q = new LinkedList<>();
//         q.offer(new int[]{row, col});
//         visited[row][col] = true;
        
//         int d = 0;
//         while (!q.isEmpty()) {
//             int size = q.size();
//             d++;
//             for (int i = 0; i < size; i++) {
//                 int[] cur = q.poll();
//                 int r = cur[0];
//                 int c = cur[1];
//                 for (int k = 0; k < 4; k++) {
//                     int rr = dirs[k][0] + r;
//                     int cc = dirs[k][1] + c;
//                     if (!isValid(rr, cc, grid, visited)) continue;                   
//                     if (grid[rr][cc] == 0) {
//                         dist[rr][cc] += d;
//                         canReach[rr][cc]++;
//                         q.offer(new int[]{rr, cc});                        
//                     }
//                     visited[rr][cc] = true;
//                 }
//             }
//         }
        
//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 if (!visited[i][j] && grid[i][j] == 1) {
//                     return false;
//                 }
//             }
//         }
        
//         return true;
        int m = grid.length; int n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        visited[x][y] = true;
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        int d = 0;
        
        while(!q.isEmpty()) {
            int s = q.size();
            ++d;
            for(int i = 0; i < s; ++i) {                        
                int[] cur = q.poll();
                int r = cur[0]; int c = cur[1];
                for(int j = 0; j < 4; ++j) {
                    int rr = r + dirs[j][0];
                    int cc = c + dirs[j][1];
                    if(!isValid(rr, cc, grid, visited)) continue;
                    if(grid[rr][cc] == 0) {
                        dist[rr][cc] += d;
                        ++canReach[rr][cc];
                        q.offer(new int[]{rr, cc});
                    }
                    visited[rr][cc] = true;
                }
            }
    
        }
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(!visited[i][j] && grid[i][j] == 1) return false;
            }
        
        return true;
    }
    
    boolean isValid(int rr, int cc, int[][] grid, boolean[][] visited) {
//              if (rr > grid.length - 1 ||
//            rr < 0 || cc < 0 || cc > grid[0].length - 1) return false;
//         if (visited[rr][cc]) return false;
//         if(grid[rr][cc] == 2) return false;
        
//         return true;
        if(rr < 0 || rr >= grid.length || cc < 0 || cc >= grid[0].length || visited[rr][cc]) return false;
        if(grid[rr][cc] == 2) return false;
        return true;
    }
}