class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        vector<int> L;
        for(int x = N + 1; x > 0; x /= 10) L.insert(L.begin(), x % 10);
        int res = 0; int n = L.size();
        for(int i = 1; i < n; ++i) res += 9 * A(9, i - 1);
        unordered_set<int> seen;
        
        for(int i = 0; i < n; ++i) {
            for(int j = i > 0 ? 0 : 1; j < L[i]; ++j) {
                if(seen.find(j) == seen.end()) res += A(9 - i, n - i - 1);
            }
            if(seen.find(L[i]) != seen.end()) break;
            seen.insert(L[i]);
        }
        
        return N - res;
    }
    
    int A(int m, int n) {
        return n == 0 ? 1 : A(m, n - 1) * (m - n + 1);
    }
};