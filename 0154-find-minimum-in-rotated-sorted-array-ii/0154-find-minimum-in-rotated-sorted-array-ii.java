class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        while(l < r && nums[l] == nums[r]) ++l;
        while(l < r) {
            int m = (r - l) / 2 + l;
            if(nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        return nums[r];
    }
}