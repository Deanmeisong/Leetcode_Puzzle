using LL = long long;
class Solution {
public:
    string subStrHash(string s, int power, int m, int k, int hashValue) {
        int pos = -1, n = s.size();
        LL p = 1; LL h = 0;
        for(int i = 0; i < k - 1; ++i) p = p * power % m;
        
        for(int i = n - 1; i >= 0; --i) {
            if(i + k < n) {
                h = h - (s[i + k] - 'a' + 1) * p % m;
                h = (h + m) % m;
            }

            h = (h * power % m + s[i] - 'a' + 1) % m;
            h = (h + m) % m;
            if(i + k <= n && h == hashValue) pos = i;

        }
        
        return s.substr(pos, k);
    }
};