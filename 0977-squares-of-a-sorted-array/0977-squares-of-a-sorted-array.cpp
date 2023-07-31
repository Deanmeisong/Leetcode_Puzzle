class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = nums.size() - 1, l = 0, h = i;
        vector<int> res(i + 1);
        while(l <= h) {
            int lo = square(nums[l]);
            int hi = square(nums[h]);
            if(lo <= hi) {
                res[i] = hi;
                --h;
            }
            else {
                res[i] = lo;
                ++l;
            }
            --i;
        }
        return res;
    }
    
    int square(int x) {
        return x * x;
    }
};