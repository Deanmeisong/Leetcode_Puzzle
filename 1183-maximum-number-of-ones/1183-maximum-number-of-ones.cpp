class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        priority_queue<int> pq;
        for(int r = 0; r < sideLength; ++r)
            for(int c = 0; c < sideLength; ++c)
                pq.push((1 + (width - 1 - r) / sideLength) * (1 + (height - 1 - c) / sideLength));
                
        int res = 0;
        int i = 0;
        while(!pq.empty() && i < maxOnes) {
            res += pq.top(); pq.pop(); ++i;
        }
        return res;
    }
};