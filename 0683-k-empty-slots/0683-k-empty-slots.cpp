class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        if(n == 0 or k >= n) return -1;
        set<int> s;
        for(int i = 0; i < n; ++i) {
            int x = bulbs[i];
            auto l = s.insert(x).first;
            auto r = l;
            if(l != s.begin() and *(--l) == x - k - 1) {
                return i + 1;
            }
            if(r != s.end() and *(++r) == x + k + 1) {
                return i + 1;
            }
        }
        return -1;
    }
};