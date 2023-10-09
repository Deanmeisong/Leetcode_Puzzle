class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        vector<int> count(1e5 + 1); vector<int> presum(1e5 + 1); vector<int> visited(1e5 + 1, 0);
        for(int x : nums) ++count[x];
        long long ret = 0;
        int M = 1e9+7;

        
        for(int x = 1; x <= 1e5; ++x) 
            presum[x] = presum[x - 1] + count[x];

        for(int x : nums) {
            if(visited[x] == 1) continue;
            long long ans = 0;
            int k = 1;
            for(;x * k + x - 1<= 1e5; ++k) {
                ans = ans + (presum[x * k + x - 1] - presum[x * k - 1]) * k % M;
                ans %= M;
            }
            
            if(k * x + x - 1 > 1e5 && k * x - 1 <= 1e5) {
                ans = ans + (presum[1e5] - presum[x * k - 1]) * k % M;
                ans %= M;
            }
            ret = (ret + ans * count[x]) % M;
            visited[x] = 1;
        }
        
        
        return ret;
    }
};