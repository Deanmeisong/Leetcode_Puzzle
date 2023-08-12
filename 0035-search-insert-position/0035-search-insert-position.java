class Solution {
    public int searchInsert(int[] nums, int target) {
        // int n = nums.length;
        // if(target > nums[n - 1]) return n;
        // if(target < nums[0]) return 0;
        // int l = 0, r = n - 1;
        // while(l < r) {
        //     int m = (r - l) / 2 + 1;
        //     if(nums[m] == target) return m;
        //     else if(nums[m] > target) r = m;
        //     else l = m + 1;
        // }
        // return l;
         int pivot, left = 0, right = nums.length - 1;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      if (nums[pivot] == target) return pivot;
      if (target < nums[pivot]) right = pivot - 1;
      else left = pivot + 1;
    }
    return left;
    }
}