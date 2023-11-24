using LL = long long;
class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> count;
        LL ret = 0;
        int total = 0;
        for(int i = 0; i < n; ++i) {
            if(nums1[i] == nums2[i]) {
                ++total;
                ++count[nums1[i]];
                ret += i;
            }
        }
        
        int maxCount = 0;
        for(auto& [k, v] : count) maxCount = max(maxCount, v);
        int maxNum = -1;
        for(auto& [k, v] : count) {
            if(v == maxCount) {
                maxNum = k;
                break;
            }
        }
        
        if(maxCount <= total - maxCount) return ret;
        
        int extra = maxCount - (total - maxCount);
        for(int i = 0; i < n; ++i) {
            if(extra == 0) break;
            if(nums1[i] == nums2[i]) continue;
            if(nums1[i] == maxNum or maxNum == nums2[i]) continue;
            ret += i;
            --extra;
        }
        
        if(extra == 0) return ret;
        return -1;
        
    }
};