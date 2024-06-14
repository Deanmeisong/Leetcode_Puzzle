class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int dp1 = 0, dp0 = 0, ans = 0;
        for(int x : nums) {
            if(x == 1) {
                ++dp0; ++dp1;
            } else {
                dp1 = dp0+1;
                dp0 = 0;
            }
            ans = Math.max(ans, Math.max(dp1, dp0));
        }
        return ans;
    }
}