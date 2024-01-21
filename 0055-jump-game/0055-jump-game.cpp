class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int far = 0;
        for(int i = 0; i < nums.size(); ++i) {
            far = max(far, nums[i] + i);
            if(i >= far && i != nums.size() - 1) return false;
            if(far >= nums.size() - 1) return true;
        }
        return false;
    }
};