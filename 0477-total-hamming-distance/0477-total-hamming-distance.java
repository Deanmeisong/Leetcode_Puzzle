class Solution {
    public int totalHammingDistance(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for(int j =0; j < 32; ++j) {
            int b = 0;
            for(int i = 0; i < n; ++i)
                b += (nums[i] >> j) & 1;
            ans += (n - b) * b;
        }
        return ans;
    }
}