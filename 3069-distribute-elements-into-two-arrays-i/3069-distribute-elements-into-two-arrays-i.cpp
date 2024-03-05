class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1; vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i = 2; i < nums.size(); ++i) {
            if(arr1.back()>arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        vector<int> ans(arr1);
        for(int a2 : arr2) ans.push_back(a2);
        return ans;
    }
};