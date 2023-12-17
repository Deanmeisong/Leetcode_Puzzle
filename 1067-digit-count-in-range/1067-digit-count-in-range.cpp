class Solution {
public:
    int digitsCount(int d, int low, int high) {
        return helper(d, high) - helper(d, low - 1);
    }
    
    int helper(int d, int n) {
        string s = to_string(n);
        int len = s.length();
        int cnt = 0;
        
        if(d != 0) {
            for(int i = 1; i <= len; ++i) {
                int base = pow(10, i);
                cnt += (n / base) * pow(10, i - 1);
                int x = s[len - i] - '0';
                if(x > d) cnt += pow(10, i - 1);
                else if(x == d) cnt += n % (int)(pow(10, i - 1)) + 1;
            }
        } else {
            for(int i = 1; i < len; ++i) {
                int base = pow(10, i);
                cnt += (n / base - 1) * pow(10, i - 1);
                int x = s[len - i] - '0';
                if(x > d) cnt += pow(10, i - 1);
                else if(x == d) cnt += n % (int)(pow(10, i - 1)) + 1;
            }
        }
        
        return cnt;
        
    }
};