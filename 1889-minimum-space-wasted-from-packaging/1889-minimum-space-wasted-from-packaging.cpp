class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(), packages.end());
        long res = LONG_MAX, m = 1e9 + 7, sum = 0;
        
        for(int p : packages) sum += p;
        
        for(auto& b : boxes) {
            sort(b.begin(), b.end());
            if(b.back() < packages.back()) continue;
            // int j = 0, i = 0; long cur = 0;
            long cur = 0, i = 0, j;
            for(int b1 : b) {
                j = upper_bound(packages.begin(), packages.end(), b1) - packages.begin();
                cur += (j - i) * b1;
                i = j;
            }
            res = min(res, cur);
        }
        
        return res < LONG_MAX ? (res - sum) % m : -1;
    }
};