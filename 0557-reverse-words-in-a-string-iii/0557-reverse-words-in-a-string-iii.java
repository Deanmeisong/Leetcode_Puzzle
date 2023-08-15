class Solution {
    public String reverseWords(String s) {
        char[] cs = s.toCharArray();
        for(int i = 0; i < cs.length; ++i) {
            if(cs[i] != ' ') {
                int j = i;
                // for(;j < cs.length && cs[j] != ' '; ++j);
                while (j + 1 < cs.length && cs[j + 1] != ' ') { j++; } 
                reverse(cs, i, j);
                i = j;
            }
        }
        // return cs.toString();
                return new String(cs);

    }
    
    void reverse(char[] cs, int i, int j) {
        for(;i < j; ++i, --j) {
            char temp = cs[i];
            cs[i] = cs[j];
            cs[j] = temp;
        }
    }
}