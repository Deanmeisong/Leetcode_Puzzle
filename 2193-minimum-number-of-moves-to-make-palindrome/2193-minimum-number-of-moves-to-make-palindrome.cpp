class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ret = 0, n = s.length(), count = 0;
        
        for(int i = 0; i < n / 2; ++i) {
            int j = n - 1 - count;
            while(s[i] != s[j]) --j;
            if(i == j) ret += n/2 - i;
            else {
                int k = n - count - 1 - j;
                ret += k;
                ++count;
                while(k--) {
                    int tmp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = tmp;
                    ++j;
                }
            }
        }
        
        return ret;
    }
};