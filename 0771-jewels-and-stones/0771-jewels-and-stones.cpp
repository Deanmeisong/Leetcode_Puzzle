class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        vector<int> js(128);
        for(char j : jewels)
            ++js[j];
        for(char s : stones)
            res += (js[s] > 0);
        return res;
    }
};