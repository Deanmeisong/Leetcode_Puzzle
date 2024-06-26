class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, dp1 = 0, dp0 = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 1) {
                ++dp1; ++dp0;
            } else {
                dp1 = dp0+1;
                dp0 = 0;
            }
            ans = max(ans, dp1);
        }
        return ans;
    }
};