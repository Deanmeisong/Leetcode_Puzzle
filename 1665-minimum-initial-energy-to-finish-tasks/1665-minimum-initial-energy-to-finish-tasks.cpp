class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] - a[0] < b[1] - b[0];
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), cmp);
        int ret = 0;
        for(auto t : tasks) ret = max(ret + t[0], t[1]);
        return ret;
    }
};