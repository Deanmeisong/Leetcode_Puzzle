class Solution {
    public int maximumBeauty(int[] flowers) {
        Map<Integer, Integer> m = new HashMap<>();
        int res = Integer.MIN_VALUE;
        int sum = 0;
        for (int b : flowers) {
            if (m.containsKey(b)) {
                res = Math.max(res, sum - m.get(b) + 2 * b);
            }
            if (b > 0) {
                sum += b;
            }
            if (!m.containsKey(b)) {
                m.put(b, sum);
            }
        }
        return res;
    }
}