class Solution {
    public boolean canDivideIntoSubsequences(int[] nums, int k) {
        int group = 1, cur = 0, n = nums.length;
        for(int i = 1; i < n; ++i) {
            cur = nums[i - 1] < nums[i] ? 1 : cur + 1;
            group = Math.max(group, cur);
        }
        return group * k <= n;
    }
}