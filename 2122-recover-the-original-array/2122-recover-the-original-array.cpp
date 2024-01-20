class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size() / 2;
        for(int i = 1; i <= n; ++i) {
            if(nums[0] == nums[i]) continue;
            if((nums[i] - nums[0]) % 2 == 1) continue;
            int k = (nums[i] - nums[0]) / 2;
            
            vector<int> visited(2*n, 0);
            vector<int> rets;
            int left = 0, right = 1;
            int flag = 1;
      
            for(int t = 0; t < n; ++t) {
                while(visited[left] == 1) ++left;
                if(left == 2 * n) {
                    flag = 0;
                    break;
                }
                visited[left] = 1;
                while(right < 2 * n  && (visited[right] == 1 || nums[left] != nums[right] - 2 * k)) ++right;
                if(right < 2 * n) visited[right] = 1;
                else {
                    flag = 0;
                    break;
                }
                rets.push_back(nums[left] + k);
    
            }
            
            if(flag) {
                return rets;
            }
            
        }
        return {};
    }
};