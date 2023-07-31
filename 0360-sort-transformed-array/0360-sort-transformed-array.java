class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int i = a >= 0 ? nums.length - 1 : 0, l = 0, h = nums.length - 1;
        int[] res = new int[nums.length];
        
        while(l <= h) {
            int lo = getV(a, b, c, nums[l]);
            int hi = getV(a, b, c, nums[h]);
            if(a >= 0) {
                if(lo <= hi) {
                    res[i] = hi;
                    --h;
                } else {
                    res[i] = lo;
                    ++l;
                }
                --i;
            } else {
                if(lo <= hi) {
                    res[i] = lo;
                    ++l;
                } else {
                    res[i] = hi;
                    --h;
                }
                ++i;
            }

                          
        }
        
        return res;
    }
    
    int getV(int a, int b, int c, int x) {
        return a * x * x + b * x + c;
    }
}