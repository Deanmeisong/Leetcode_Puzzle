class Solution {
    public int romanToInt(String s) {
        char[] romans = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int[] ints = {1000, 500, 100, 50, 10, 5, 1};
        HashMap<Character, Integer> m = new HashMap<>();
        for (int i = 0; i < romans.length; i++) {
            m.put(romans[i], ints[i]);
        }
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1) {
                if (m.get(s.charAt(i)) >= m.get(s.charAt(i + 1))) {
                    ans += m.get(s.charAt(i));
                } else {
                    ans -= m.get(s.charAt(i));
                }
            } else {
                ans += m.get(s.charAt(i));
            }
        }
        return ans;
    }
}