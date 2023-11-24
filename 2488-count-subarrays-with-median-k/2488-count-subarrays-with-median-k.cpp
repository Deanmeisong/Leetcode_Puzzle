class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        for(int& x : nums) {
            if(x > k) x = 1;
            else if(x < k) x = -1;
            else x = 0;
        }
        
        unordered_map<int, int> evenSum;
        unordered_map<int, int> oddSum;
        
        int ret = 0, s = 0;
        evenSum[0] = 1;
        
        for(int i = 0; i < nums.size(); ++i) {
            s += nums[i];
            if(i&1) {
                ret += oddSum[s-0];
                ret += evenSum[s-1];
                ++evenSum[s];
            } else {
                ret += evenSum[s-0];
                ret += oddSum[s-1];
                ++oddSum[s];
            }
  
        }
        
        return ret;
    }
};