class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, numOf0 = 0, left = 0, right = 0;
        while(right < nums.size()) {
            if(nums[right] == 0) numOf0++;
            while(numOf0 == 2) {
                if(nums[left++] == 0) numOf0--;
            }
            ans = max(ans, right - left + 1);
            ++right;
        }
        return ans;
    }
};