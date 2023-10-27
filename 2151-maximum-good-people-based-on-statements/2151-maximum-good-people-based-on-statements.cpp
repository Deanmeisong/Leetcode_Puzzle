class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        const int n = statements.size();
        
        function<bool(int)> valid = [&](int s) {
            for(int i = 0; i < n; ++i) {
                if(!((s>>i) & 1)) continue;
                for(int j = 0; j < n; ++j) {
                    bool good = (s>>j) & 1;
                    if((good && statements[i][j] == 0) || (!good && statements[i][j] == 1)) return false;
                }
            }
            return true;
        };
         
        int ans = 0;
        for(int s = 0; s < (1<<n); ++s)
            if(valid(s)) ans = max(ans, __builtin_popcount(s));
        return ans;
    }
};