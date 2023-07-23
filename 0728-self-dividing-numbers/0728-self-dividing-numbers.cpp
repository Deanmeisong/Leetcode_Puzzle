class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        
        for(int n = left; n <= right; ++n) {
            bool valid = true;
            int t = n;
            while(t and valid) {
                const int r = t % 10;
                if(r == 0 or n % r) valid = false;
                t /= 10;
            }
            if(valid) ans.push_back(n);
        }
        
        return ans;
    }
};