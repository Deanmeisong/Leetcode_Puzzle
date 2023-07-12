class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while(i < word.length() and j < abbr.length()) {
            char c = abbr[j];
            if(isdigit(c)) {
                int num = c - '0';
                if(num == 0) return false;
                while(j + 1 < abbr.length() and isdigit(abbr[j + 1])) {
                    num = 10 * num + (abbr[j + 1] - '0');
                    ++j;
                }
                i += num;
                ++j;
            } else {
                if(word[i] != abbr[j]) return false;
                ++i; ++j;
            }
        }
        
        return i == word.length() and j == abbr.length();
    }
};