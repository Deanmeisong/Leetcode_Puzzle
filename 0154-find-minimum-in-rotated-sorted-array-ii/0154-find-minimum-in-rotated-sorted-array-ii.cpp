class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r && nums[l] == nums[r]) ++l;
        while(l < r) {
            int m = (r - l) / 2 + l;
            if(nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        return nums[r];
    }
};