using LL = long long;
class Solution {
public:
    LL M = 1e9 + 7;
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        LL ret = 0; LL sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            LL square = (LL)nums[i]*(LL)nums[i]%M;
            if(i >= 1) {
                sum = sum*2%M + (LL)nums[i-1];
            }
            ret += sum*square%M + square*nums[i]%M;
            ret %= M;
        }
        return ret;
    }
};