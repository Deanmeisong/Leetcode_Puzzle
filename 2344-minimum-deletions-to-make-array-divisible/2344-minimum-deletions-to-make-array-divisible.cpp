class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int x = numsDivide[0];
        for(int num : numsDivide) x = gcdE(x, num);
        for(int i = 0; i < nums.size(); ++i)
            if(x % nums[i] == 0) return i;
        return -1;
    }
    
    int gcdE(int a, int b) {
        while(b > 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
};