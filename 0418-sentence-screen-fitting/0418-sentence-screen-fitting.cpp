class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        vector<int> cache(n);
        
        for(int i = 0; i < n; ++i) {
            int index = i, len = 0, wordNum = 0;
            while(len + sentence[(index % n)].length() <= cols) {
                len += sentence[index % n].length() + 1;
                ++index;
                ++wordNum;
            }
            cache[i] = wordNum;
        }
        
        int index2 = 0, words = 0;
        
        for(int i = 0; i < rows; ++i) {
            words += cache[index2];
            index2 = (index2 + cache[index2]) % n;
        }
        
        return words / n;
        
    }
};