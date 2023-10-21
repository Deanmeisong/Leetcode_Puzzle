class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> arr(s.begin(), s.end());
        sort(arr.begin(), arr.end());
        int j = 0;
        int ret = INT_MAX;
        for(int i = 0; i < arr.size(); ++i) {
            while(j < arr.size() && arr[j] - arr[i] + 1 <= n) {
                ret = min(ret, n - j + i - 1);
                ++j;
            }
            // j = i + 1;
        }

        return ret;
    }
};