class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int b = -1;
        int mi = -1; int ma = -1;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] < minK || nums[i] > maxK) {
                b = i;
                continue;
            }
            
            if(nums[i] == minK) mi = i;
            if(nums[i] == maxK) ma = i;
            
            res += max(0, min(mi, ma) - b);
        }
        return res;
    }
};