class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0, sum2 = 0;
        int ans = INT_MIN;
        for(int x : nums1) sum1 += x;
        for(int y : nums2) sum2 += y;
        ans = max(sum1, sum2);
        int first = 0, second = 0, max1 = 0, max2 = 0;
        
        for(int i = 0; i < nums1.size(); ++i) {
            first += nums2[i] - nums1[i];
            second += nums1[i] - nums2[i];
            if(first < 0) first = 0;
            if(second < 0) second = 0;
            
            max1 = max(max1, first);
            max2 = max(max2, second);
        }
        
        ans = max(sum1 + max1, sum2 + max2);
        return ans;
    }
};