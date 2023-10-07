class Solution {
public:
    string nextPalindrome(string num) {
        int n = num.size();
        if(n <= 3) return "";
        int m = n / 2;
        int idx = -1;
        for(int i = m - 2; i >= 0; --i) {
            if(num[i] < num[i + 1]) {
                idx = i;
                break;
            }
        }
        
        if(idx == -1) return "";
        int lastLarge = idx + 1;
        for(int i = idx + 1; i < m; ++i) {
            if(num[i] > num[idx]) {
                lastLarge = i;
            }
        }
        
        swap(num[idx], num[lastLarge]);
        reverse(num.begin() + idx + 1, num.begin() + m);
        int j = 0;
        for(int i = n - 1; i >= m; --i) {
            num[i] = num[j++];
        }
        return num;
    }
};