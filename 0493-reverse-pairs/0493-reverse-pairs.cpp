class Solution {
public:
    int temp[50001];
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        return helper(nums, sorted, 0, n - 1);
    }
    
    int helper(vector<int>& nums, vector<int>& sorted, int a, int b) {
        if(a >= b) return 0;
        int ret = 0;
        int mid = (b - a) / 2 + a;
        ret += helper(nums, sorted, a, mid);
        ret += helper(nums, sorted, mid + 1, b);
        
        for(int j = mid + 1; j <= b; ++j) {
            auto iter = upper_bound(sorted.begin() + a, sorted.begin() + mid + 1, 2 * (long)(nums[j]));
            ret += sorted.begin() + mid + 1 - iter;
        }
        
        inplace_merge(sorted.begin() + a, sorted.begin() + mid + 1, sorted.begin() + b + 1);
        return ret;
    }
};