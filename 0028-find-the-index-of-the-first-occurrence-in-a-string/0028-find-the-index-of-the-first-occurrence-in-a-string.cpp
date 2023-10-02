class Solution {
public:
    int strStr(string haystack, string needle) {
             int l = haystack.length(), l2 = needle.length();
        for(int i = 0; i <= l - l2; ++i) {
            int j = 0;
            while(j < l2 and haystack[i + j] == needle[j]) ++j;
            if(j == l2) return i;
        }
        return -1;
    }
};