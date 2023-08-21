class Solution {
    public int longestDecomposition(String s) {
        int res = 0; int n = s.length(); String l = ""; String r = "";
        for(int i = 0; i < n; ++i) {
            l += s.charAt(i); r = s.charAt(n - i - 1) + r;
            if(l.equals(r)) {
                ++res;
                l = "";
                r = "";
            }
        }
        return res;
    }
}