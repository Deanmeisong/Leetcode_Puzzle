class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> indices(101, -1); 
        for(int i = 0; i < nums.size(); ++i)
            indices[nums[i]] = i; 
        
        int maxIndex = -1;
        
        for(int i = 100; i >= 0; --i) {
            if(indices[i] >= 0) {
                maxIndex = i;
                break;
            }
        }
        
        for(int i = maxIndex - 1; i >= 0; --i) {
            if(indices[i] >= 0 and maxIndex < 2 * i) return -1; 
        }
        
        return indices[maxIndex];
    }
};