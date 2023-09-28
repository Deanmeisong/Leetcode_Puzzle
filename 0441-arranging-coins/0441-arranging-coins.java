class Solution {
    public int arrangeCoins(int n) {
        int i = 1; long res = 1;
        while(res < n) {
            ++i;
            res += i;
        }
        return res > n ? i - 1 : i;
    }
}