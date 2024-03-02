class Solution {
public:
    int maxIntersectionCount(vector<int>& y) {
        map<float, int> Map;
        int n = y.size();
        for(int i = 1; i < n; ++i) {
            int a = y[i - 1]; int b = y[i];
            if(a < b) {
                Map[a] += 1; Map[b] -= 1;
            } else {
                Map[a + 0.5] -= 1; Map[b + 0.5] += 1;
            }
        }
        
        Map[y[n - 1]] += 1;
        Map[y[n - 1] + 0.5] -= 1;
        
        int count = 0; int res = 0;
        for(auto& [k, v] : Map) res = max(res, count += v);
        return res;
     
    }
};