class Solution {
    public String smallestGoodBase(String n) {
        long target = Long.parseLong(n);
        int n2 = (int)(Math.log(target) / Math.log(2));
        for(int m = n2; m >= 2; --m) {
            long sum = 1;
            long k = (long)Math.pow(target, 1.0 / m);
            long base = 1;
            if(k == 1) continue;
            for(int i = 1; i <= m; ++i) {
                base *= k;
                sum += base;
            }
            if(sum == target) return String.valueOf(k);

        }
        return String.valueOf(target - 1);
    }
}