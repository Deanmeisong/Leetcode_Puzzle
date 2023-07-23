class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        
        for(int n = left; n <= right; ++n) {
            const string s = to_string(n);
            bool valid = true;
            for(char c : s) {
                if((c - '0') == 0 or n % ((c - '0')) != 0) {
                    valid = false;
                    break;
                }
            }
            if(valid) ans.push_back(n);
        }
        
        return ans;
    }
};