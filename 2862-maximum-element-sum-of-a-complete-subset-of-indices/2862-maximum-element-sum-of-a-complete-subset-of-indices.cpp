using LL = long long;
class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        LL ret = 0;
        int k = 1;
        while(k <= n) {
            LL sum = 0;
            for(int i = 1; k*i*i <= n; ++i) {
                sum += nums[k*i*i - 1];
            }
            ret = max(sum, ret);
            ++k;
        }
        return ret;
    }
};