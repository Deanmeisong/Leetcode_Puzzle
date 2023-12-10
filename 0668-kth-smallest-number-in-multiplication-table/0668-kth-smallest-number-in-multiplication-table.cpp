class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        
        function<int(int)> check = [&](int val) {
            int cnt = 0;
            for(int i = 1; i <= m; ++i)
                cnt += min(n, val / i);
            return cnt;
        };
        
        int l = 1, r = m * n;
        while(l < r) {
            int val = (r - l) / 2 + l;
            if(check(val) < k) l = val + 1;
            else r = val;
        }
        
        return l;
    }
    
};