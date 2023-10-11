class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> res;
        for(int i = digits.size() - 1; i >= 0 or carry; --i) {
            if(i >= 0) carry += digits[i];
            res.push_back(carry % 10);
            carry /= 10;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};