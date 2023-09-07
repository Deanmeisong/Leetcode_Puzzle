class Solution {
    public int closestToTarget(int[] arr, int target) {
        HashSet<Integer> s = new HashSet<>();
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length; ++i) {
            HashSet<Integer> s1 = new HashSet<>();
            for (int x : s) {
                s1.add(x & arr[i]);
            }
            s1.add(arr[i]);
            for (int x : s1) {
                res = Math.min(res, Math.abs(x - target));
            }
            s = s1;
        }
        return res;
    }
}