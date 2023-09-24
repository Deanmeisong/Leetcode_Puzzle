class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = 10 * res + x % 10;
            x /= 10;
        }
        return (res > INT_MAX or res < INT_MIN) ? 0 : res;
    }
};