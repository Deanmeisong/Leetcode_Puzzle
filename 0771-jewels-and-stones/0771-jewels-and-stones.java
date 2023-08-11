class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        int count = 0;
        int[] js = new int[128];
        for(char j : jewels.toCharArray()) {
            js[j - '0']++;
        }
        for(char s : stones.toCharArray()) {
            if(js[s- '0'] > 0) {
                ++count;
            }
        }
        return count;
    }
}