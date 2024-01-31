using LL = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<LL> presum(n + 1);
        for(int i = 1; i <= n; ++i) presum[i] = presum[i - 1] + nums[i];        
        
        LL ret = 0;
        for(int i = 1; i <= n; ++i) {
            if(nums[i] >= k) continue;
            
            LL l = 1, r = i;
            while(l < r) {
                int m = r - (r - l) / 2;
                if((presum[i] - presum[i - m]) * m < k) l = m;
                else r = m - 1;
            }
            ret += l;
            
        }
        return ret;
    }
};