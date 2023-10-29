class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_set<int> yueshu;
        for(int i = 1; i * i <= k; ++i) {
            if(k % i) continue;
            yueshu.insert(i);
            yueshu.insert(k/i);
        }
        
        map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); ++i) {
            for(int y : yueshu)
                if(nums[i] % y == 0)
                    m[y].push_back(i);
        }
        
        long long ret = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            int a = gcd(nums[i], k);
            int b = k / a;
            auto iter = upper_bound(m[b].begin(), m[b].end(), i);
            ret +=  m[b].end() - iter;
        }
        
        return ret;
    }
};