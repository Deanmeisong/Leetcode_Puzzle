class Solution {
    public int mySqrt(int x) {

        if(x == 1) return 1;
        int l = 1, r = x;
        while(l < r) {
            int m = (r - l) / 2 + l;
            if(m > x / m) r = m;
            else l = m + 1;
        }
        return l - 1;
    }
}