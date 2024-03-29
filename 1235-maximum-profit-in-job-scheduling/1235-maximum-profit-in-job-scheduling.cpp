class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n = s.size();
        vector<vector<int>> js;
        for(int i = 0; i < n; ++i) js.push_back({s[i], e[i], p[i]});
        sort(js.begin(), js.end(),cmp);
        vector<pair<int,int>> dp;
        dp.push_back({-1, 0});
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int cur = ans;
            auto iter = upper_bound(dp.begin(), dp.end(), make_pair(js[i][0], INT_MAX));
            cur = max(cur, prev(iter,1)->second + js[i][2]);
            dp.push_back({js[i][1], cur});
            ans = max(cur, ans);
        }
        return ans;
    }
};