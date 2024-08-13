class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int d[1001]{};
        for(auto& trip : trips) {
            int x = trip[0], from = trip[1], to = trip[2];
            d[from] += x;
            d[to] -= x;
        }
        int sum = 0;
        for(int x : d) {
            sum += x;
            if(sum > capacity) return false;
        }
        return true;
    }
};