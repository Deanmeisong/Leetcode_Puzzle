using LL = long long;
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        LL ret = 0;
        for(int i = nums.size() - 2; i >= 0; --i) {
            int y = nums[i]; int x = nums[i+1];
            if(y <= x) continue;
            if(y%x == 0) {
                ret += y/x-1;
                nums[i] = x;
            } else {
                ret += y/x;
                nums[i] = y/(y/x+1);
            }
        }
        return ret;
    }
};