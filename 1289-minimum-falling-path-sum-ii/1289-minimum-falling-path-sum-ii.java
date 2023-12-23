class Solution {
    public int minFallingPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        List<List<Integer>> dp = new ArrayList<>(m);
        for (int i = 0; i < m; i++) {
            dp.add(new ArrayList<>(Collections.nCopies(n, 0)));
        }
        for (int i = 0; i < n; i++) {
            dp.get(0).set(i, grid[0][i]);
        }
        for (int r = 1; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int min_value = Integer.MAX_VALUE;
                for (int k = 0; k < n; k++) {
                    if (k == c) {
                        continue;
                    }
                    min_value = Math.min(min_value, dp.get(r - 1).get(k));
                }
                dp.get(r).set(c, grid[r][c] + min_value);
            }
        }
        return Collections.min(dp.get(m - 1));
    }
}