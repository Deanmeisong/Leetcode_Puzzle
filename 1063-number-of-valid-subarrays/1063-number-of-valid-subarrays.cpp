class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res;
        int ans = 0;
        for(int i = n - 1; i >= 0; --i) {
            while(!res.empty() && nums[res.back()] >= nums[i]) res.pop_back();
            if(res.empty()) ans += n - i;
            else ans += res.back() - i;
            res.push_back(i);
        }
        return ans;
    }
};