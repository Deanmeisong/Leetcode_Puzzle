class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> t;
        for(int i = 0; i <= n; ++i) {
            t.emplace_back(max(0, i - ranges[i]), min(i + ranges[i], n));
        }
        sort(t.begin(), t.end());
        int e = 0, l = 0, ans = 0, i = 0;
        while(e < n) {
            while(i <= n && t[i].first <= l) {
                e = max(e, t[i++].second);
            }
            if(l == e) return -1;
            l = e;
            ++ans;
        }
        return ans;

    }
};