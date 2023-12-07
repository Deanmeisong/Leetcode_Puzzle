class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length(), cnt = 0;
        int i = n - 1;
        while(i >= 0 && !Character.isAlphabetic(s.charAt(i))) --i;
        while(i >= 0 && Character.isAlphabetic(s.charAt(i))) {
            --i;
            ++cnt;
        } 
        return cnt;
    }
}