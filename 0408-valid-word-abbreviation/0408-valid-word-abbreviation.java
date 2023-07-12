class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        int i = 0, j = 0;
        while(i < word.length() && j < abbr.length()) {
            char c = abbr.charAt(j);
            if(Character.isDigit(c)) {
                int num = c - '0';
                if(num == 0) return false;
                while(j + 1 < abbr.length() && Character.isDigit(abbr.charAt(j + 1))) {
                    num = num * 10 + (abbr.charAt(j + 1) - '0');
                    ++j;
                }
                i += num;
                ++j;
            } else {
                if(word.charAt(i) != abbr.charAt(j)) return false;
                ++i; ++j;
            }
        }
        return i == word.length() && j == abbr.length();
    }
}