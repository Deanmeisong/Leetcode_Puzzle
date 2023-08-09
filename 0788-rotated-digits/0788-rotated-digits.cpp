class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; ++i) 
            ans += helper(i);
        return ans;
    }
    
    bool helper(int x) {
        int flag = 0;
        while(x) {
            int t = x % 10;
            x /= 10;
            if(t == 4 or t == 7 or t == 3) return false;
            if(t == 2 or t == 5 or t == 6 or t == 9) flag = 1;
        }
        return flag;
    }
};