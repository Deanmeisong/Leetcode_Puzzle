class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int j = 0; j < 32; ++j) {
            int bit = 0;
            for(int i = 0; i < n; ++i) {
                bit += (nums[i] >> j) & 1;
            }
            ans += (n - bit) * bit;
        }
        return ans;
    }
};