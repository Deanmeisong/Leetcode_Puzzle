class Solution {
public:
    int minimumScore(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        vector<int> left(n, m);
        int j = 0;
        for(int i = 0; i < n; ++i) {
            while(j < m && s[j] != t[i]) ++j;
            if(j < m) {
                left[i] = j;
                ++j;
            }
        }
        
        j = m - 1;
        vector<int> right(n, -1);
        for(int i = n -1; i >= 0; --i) {
            while(j >= 0 && s[j] != t[i]) --j;
            if(j >= 0) {
                right[i] = j;
                --j;
            }
        }
 
        function<bool(int)> isOk = [&](int len) {
            if(right[len] >= 0) return true;
            if(left[n - len - 1] < m) return true;
            for(int i = 1; i + len < n; ++i)
                if(left[i - 1] < right[i + len]) return true;
            return false;
        };

        int l = 0, r = n;
        while(l < r) {
            int mid = (r - l) / 2 + l;
            if(isOk(mid)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
    
};