class Solution {
    public String findContestMatch(int n) {
        String[] m = new String[n];
        for(int i = 0; i < n; ++i) {
            m[i] = String.valueOf(i + 1);
        }
        
        while(n > 1) {
            for(int i = 0; i < n / 2; ++i) {
                m[i] = "(" + m[i] + "," + m[n - i - 1] + ")";
            }
            n /= 2;
        }
        
        return m[0];
    }
}