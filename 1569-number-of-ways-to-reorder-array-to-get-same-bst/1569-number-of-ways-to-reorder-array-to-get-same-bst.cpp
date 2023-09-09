class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size(); int kMod = 1e9 + 7;
        vector<vector<int>> c(n + 1, vector<int>(n + 1, 1));
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j < i; ++j)
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % kMod;
        
        function<int(vector<int>&)> trees = [&](vector<int>& nums) {
            int n = nums.size();
            if(n <= 2) return 1;
            vector<int> left; vector<int> right;
            for(int i = 1; i < n; ++i)
                if(nums[i] < nums[0]) left.push_back(nums[i]);
                else right.push_back(nums[i]);
            long ans = c[n - 1][left.size()];
            ans = (ans * trees(left)) % kMod;      
            ans = (ans * trees(right)) % kMod;      
            return static_cast<int>(ans);
        };

        return trees(nums) - 1;
    }
};