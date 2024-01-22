class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        vector<int> rets;
        for(int i = 0; i < n; ++i) {
            // int x = nums[i];
            // while(!rets.empty() && gcd(rets.back(), x) > 1) {
            //     x = lcm(rets.back(), x);
            //     rets.pop_back();
            // }
            // rets.push_back(x);
                        int x = nums[i];
            while (!rets.empty() && gcd(rets.back(), x)>1)
            {
                x = lcm(rets.back(), x);
                rets.pop_back();                
            }
            rets.push_back(x);
        }
        
        return rets;
    }
    
    long long lcm(long long x, long long y) {
        return x * y / gcd(x, y);
    }
};