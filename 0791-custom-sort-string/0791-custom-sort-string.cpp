class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> cache(128, INT_MAX);
        for(int i = 0; i < order.length(); ++i)
            if(cache[order[i]] == INT_MAX) cache[order[i]] = i + 1;
        std :: sort(s.begin(), s.end(), [&cache](const char& a, const char& b) {
            return cache[a] < cache[b];
        });
        return s;
    }
};