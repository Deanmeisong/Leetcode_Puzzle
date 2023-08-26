class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        vector<int> count(100001);
        vector<int> freq(100001);
        int n = nums.size();
        for (int num : nums) {
            ++count[num];
            ++freq[count[num]];
        }
        for (int i = n - 1; i > 0; --i) {
            if (count[nums[i]] * freq[count[nums[i]]] == i) return i + 1;
            --freq[count[nums[i]]];
            --count[nums[i]];
            if (count[nums[i - 1]] * freq[count[nums[i - 1]]] == i) return i + 1;
        }
        return 1;

    }
};