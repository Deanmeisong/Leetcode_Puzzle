class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        if(n == 1) return true;
        int far = 0;
        
        for(int i = 0; i < n; ++i){
            far = Math.max(far, i + nums[i]);
            if(i >= far && i != n - 1) return false;
            if(far >= n - 1) return true;
        }
        
        return false;
    }
}