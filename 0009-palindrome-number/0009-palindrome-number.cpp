class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x != 0 && x % 10 == 0) return false;
        int res = 0; int o = x;
        while(x > res) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        // cout<<res;
        return res == x || res / 10 == x;
    }
};