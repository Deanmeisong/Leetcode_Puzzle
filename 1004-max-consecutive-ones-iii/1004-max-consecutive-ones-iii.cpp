class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int left = 0, right = 0, maxLength = 0, zeroCount = 0;
        int n = nums.size();
        
        while (right < n) {
            if (nums[right] == 0) {
                zeroCount++;
            }
            
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            maxLength = std::max(maxLength, right - left + 1);
            right++;
        }
        
        return maxLength;
    }
};