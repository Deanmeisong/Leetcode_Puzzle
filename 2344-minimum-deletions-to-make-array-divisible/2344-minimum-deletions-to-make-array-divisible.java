class Solution {
    public int minOperations(int[] nums, int[] numsDivide) {
        Arrays.sort(nums);
        int x = numsDivide[0];
        for(int num : numsDivide) x = gcd(x, num);
        for(int i = 0; i < nums.length; ++i)
            if(x % nums[i] == 0) return i;
        return -1;
    }
    
    public int gcd(int a, int b) {
        while(b > 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
}