class Solution {
public:
    int minOperations(vector<int>& nums, int x, int y) {
        sort(nums.begin(), nums.end());
        int l = 0, r = INT_MAX/2;
        while(l < r) {
            int m = l + (r - l)/2;
            if(isOK(nums, m, x, y)) r = m;
            else l = m + 1;
        }
        return l;
    }
    
    bool isOK(vector<int>& nums, int k, int x, int y) {
        int count = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] < 1.0 * y * k) continue;
            count += ceil((nums[i] - y * k) * 1.0 / (x - y));
            if(count > k) return false;
        }
        return true;
    }
};