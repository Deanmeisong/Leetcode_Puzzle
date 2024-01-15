class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> dp;
        while (dp.insert(n).second) {
            int sq = 0;
            while (n > 0) {
                int base = n % 10;
                sq += base * base;
                n /= 10;
            }
            if (sq == 1) {
                return true;
            }
            n = sq;
        }
        return false;
    }
};