class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int left = 0, right = 0, num0 = 0, ans = 0;
        while(right < nums.length) {
            if(nums[right] == 0) ++num0;
            while(num0 == 2) {
                if(nums[left++] == 0) --num0;
            }
            ans = Math.max(ans, right++ - left + 1);
        }
        return ans;
    }
}