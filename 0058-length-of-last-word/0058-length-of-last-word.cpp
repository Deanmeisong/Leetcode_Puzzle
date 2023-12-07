class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0; int n = s.size();
        int i = n - 1;
        while(i >= 0 && !isalpha(s[i])) --i;
        while(i >= 0 && isalpha(s[i--])) ++cnt;
        return cnt;
    }
};