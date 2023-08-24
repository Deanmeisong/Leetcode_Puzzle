class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> count;
        for(int r = 0; r < sideLength; ++r)
            for(int c = 0; c < sideLength; ++c)
                count.push_back((1 + (width - 1 - r) / sideLength) * (1 + (height - 1 - c) / sideLength));
        
        sort(count.begin(), count.end(), greater <>());
        
        int res = 0;
        for(int i = 0; i < maxOnes; ++i) res += count[i];
        return res;
    }
};