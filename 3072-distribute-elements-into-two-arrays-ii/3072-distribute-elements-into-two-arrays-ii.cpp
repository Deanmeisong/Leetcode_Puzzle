class Solution {
public:
    int greaterCount(vector<int>& arr, int x) {
        return arr.end() - upper_bound(arr.begin(), arr.end(), x);
    }
    vector<int> resultArray(vector<int>& nums) {
        vector<int> left, ll, right, rr;
        int ln = 1, rn = 1;
        left.push_back(nums[0]); right.push_back(nums[1]);
        ll.push_back(nums[0]); rr.push_back(nums[1]);
        for(int i = 2; i < nums.size(); ++i) {
            int n1 = greaterCount(left, nums[i]);
            int n2 = greaterCount(right, nums[i]);
            if(n1 > n2) {
                left.insert(left.end() - n1, nums[i]);
                ll.push_back(nums[i]);
                ++ln;
            } else if(n1 < n2) {
                right.insert(right.end() - n2, nums[i]);
                rr.push_back(nums[i]);
                ++rn;
            } else {
                if(ln < rn) {
                    left.insert(left.end() - n1, nums[i]);
                    ll.push_back(nums[i]);
                    ++ln;
                } else if(ln > rn) {
                    right.insert(right.end() - n2, nums[i]);
                    rr.push_back(nums[i]);
                    ++rn;
                } else {
                    left.insert(left.end() - n1, nums[i]);
                    ll.push_back(nums[i]);
                    ++ln;
                }
            }
        }
        ll.insert(ll.end(), rr.begin(), rr.end());
        return ll;
    }
};