class Solution {
public:
    int minDayskVariants(vector<vector<int>>& points, int k) {
        int ans = INT_MAX;
        
        for(int a = 1; a <= 100; ++a)
            for(int b = 1; b <= 100; ++b) {
                priority_queue<int> mh;
                for(const auto& p : points) {
                    int x = p[0]; int y = p[1];
                    mh.push(abs(x - a) + abs(y - b));
                    if(mh.size() > k) mh.pop();
                }
                ans = min(ans, mh.top());
            }
        
        return ans;
    }
};