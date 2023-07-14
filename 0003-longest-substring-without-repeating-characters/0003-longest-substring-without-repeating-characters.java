class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] count = new int[130];
        int i = 0, ans = 0;
        for(int j = 0; j < s.length(); ++j) {
            while(count[s.charAt(j)] > 0 && i < j) --count[s.charAt(i++)];
            ++count[s.charAt(j)];
            ans = Math.max(ans, (j - i + 1));
        }
        return ans;
    }
}