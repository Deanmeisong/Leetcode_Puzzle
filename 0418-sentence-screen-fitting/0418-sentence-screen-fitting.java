class Solution {
    public int wordsTyping(String[] sentence, int rows, int cols) {
        int n = sentence.length;
        int[] cache = new int[n];
        
        for(int i = 0; i < n; ++i) {
            int index = i;
            int wordNum = 0;
            int len = 0;
            while((len + sentence[index % n].length()) <= cols) {
                len += sentence[index % n].length() + 1;
                wordNum++;
                index++;
            }
            cache[i] = wordNum;
        }
        
        int words = 0;
        int index = 0;
        for(int i = 0; i < rows; ++i) {
            words += cache[index];
            index = (index + cache[index]) % n;
        }
        
        return words / n; 
    }
}