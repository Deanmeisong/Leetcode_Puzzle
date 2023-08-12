class Solution {
    public int searchInsert(int[] nums, int target) {
        // if(target > nums[n - 1]) return n;
        // if(target < nums[0]) return 0;
        int l = 0, r = nums.length - 1;
        while(l <= r) {
            int m = (r - l) / 2 + l;
            if(nums[m] == target) return m;
            else if(nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
}