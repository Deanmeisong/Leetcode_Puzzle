class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int x = numsDivide[0];
        for(int num : numsDivide) x = gcd(x, num);
        for(int i = 0; i < nums.size(); ++i)
            if(x % nums[i] == 0) return i;
        return -1;
    }
};