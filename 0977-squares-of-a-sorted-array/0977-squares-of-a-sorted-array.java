class Solution {
    public int[] sortedSquares(int[] nums) {
        int i = nums.length - 1, low = 0, high = i;
        int[] res = new int[i + 1];
        while(low <= high) {
            int lo = nums[low] * nums[low];
            int hi = nums[high] * nums[high];
            if(lo <= hi) {
                res[i] = hi;
                --high;
            } else {
                res[i] = lo;
                ++low;
            }
            --i;
        }
        return res;
    }
}