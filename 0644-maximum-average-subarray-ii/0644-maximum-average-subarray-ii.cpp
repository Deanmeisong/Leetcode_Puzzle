class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double r = 10000, l = -10000;
        double ans = 0;
        while(r - l > 1e-7) {
            double mid = (r - l) / 2 + l;
            if(check(nums, mid, k)) {
                ans = mid;
                l = mid;
            } else {
                r = mid;
            }
        }
        return ans;
    }
    
    bool check(vector<int>& nums, double mid, int k) {
        int n = nums.size();
        double sum = 0, prev = 0, minPrev = 0;
        for(int i = 0; i < k; ++i) {
            sum += (nums[i] - mid);
        }
        if(sum >= 0) return true;
        for(int i = k; i < n; ++i) {
            prev += nums[i - k] - mid;
            sum += nums[i] - mid;
            minPrev = min(prev, minPrev);
            if(sum - minPrev >= 0) return true;
        }
        return false;

    }
};