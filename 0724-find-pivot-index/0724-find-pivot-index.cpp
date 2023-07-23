class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n);
        sums[0] = nums[0];
        for(int i = 1; i < n; ++i) sums[i] = nums[i] + sums[i - 1];
        
        int res = -1;
        
        if(sums[n - 1] - sums[0] == 0) return 0;
        
        for(int i = 1; i < n; ++i) 
            if(sums[i - 1] == (sums[n - 1] - sums[i])) return i;
        
        return res;
    }
};