class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> cnt = new HashMap<>();
        int ans = 0;

        for (int[] row : matrix) {
            StringBuilder s = new StringBuilder();
            for (int x : row) {
                s.append(row[0] == 0 ? x : (x ^ 1));
            }
            String key = s.toString();
            cnt.put(key, cnt.getOrDefault(key, 0) + 1);
            ans = Math.max(ans, cnt.get(key));
        }

        return ans;
    }
}