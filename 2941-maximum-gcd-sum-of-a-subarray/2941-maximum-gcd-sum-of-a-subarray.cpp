class Solution {
public:
    long long maxGcdSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long s[n+1];
        s[0] = 0;
        for(int i = 1; i <= n; ++i) s[i] = s[i-1] + nums[i-1];
        vector<pair<int, int>> f;
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            vector<pair<int, int>> g;
            for(auto [j, v] : f) {
                int x = gcd(v, nums[i]);
                if(g.empty() || g.back().second < x) 
                    g.push_back({j, x});
            }
            f = move(g);
            f.push_back({i, nums[i]});
            for(auto [j, v] : f)
                if(i - j + 1 >= k) ans = max(ans, (s[i + 1] - s[j])*v);
        }
        return ans;
    }
};