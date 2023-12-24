class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> nums(ranges.size());
        for(int i = 0; i <= n; ++i) {
            int s = max(0, i - ranges[i]);
            nums[s] = max(nums[s], i + ranges[i]);
        }
        int i = 0, e = 0, l = 0, step = 0;
        for(int i = 0; i <= n; ++i) {
            if(i > e) return -1;
            if(i > l) {++step; l = e;}
            e = max(e, nums[i]);
        }
        return step;
    }
};