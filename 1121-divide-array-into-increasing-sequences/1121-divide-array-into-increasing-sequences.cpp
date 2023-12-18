class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        int g = 1, cur = 1, n = nums.size();
        for(int i = 1; i < n; ++i) {
            cur = nums[i - 1] < nums[i] ? 1 : cur + 1;
            g = max(g, cur);
        }
        return g * k <= n;
      
    }
};