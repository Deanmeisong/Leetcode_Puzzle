using LL = long long;
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        LL ret = 0;
        int n = nums.size();
        nums.insert(nums.begin(),0);
        vector<vector<int>> pre(n+5, vector<int>(n+5));
        vector<vector<int>> post(n+5, vector<int>(n+5));
        
        for(int i = 1; i <= n; ++i)
            for(int v = 1; v <= n; ++v)
                if(nums[i] < v) pre[i][v] = pre[i-1][v] + 1;
                else pre[i][v] = pre[i-1][v];
        
        for(int i = n; i >= 1; --i)
            for(int v = 1; v <= n; ++v)
                if(nums[i] > v) post[i][v] = post[i+1][v] + 1;
                else post[i][v] = post[i+1][v];
        
        for(int i = 1; i <= n; ++i)
            for(int j = i+1; j <= n; ++j) {
                if(nums[i] > nums[j])
                    ret += pre[i-1][nums[j]] * post[j+1][nums[i]];
            }

        return ret;
    }
};