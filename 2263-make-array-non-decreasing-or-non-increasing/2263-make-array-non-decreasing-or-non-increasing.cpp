class Solution {
public:
    int convertArray(vector<int>& nums) {
        int ans = helper(nums);
        reverse(nums.begin(), nums.end());
        return min(ans, helper(nums));
    }
    
    int helper(vector<int>& nums) {
        int ret = 0;
        priority_queue<int> pq;
        for(int x : nums) {
            if(!pq.empty() && pq.top() > x) {
                ret += pq.top() - x;
                pq.pop();
                pq.push(x);
            }
            pq.push(x);
        }
        return ret;
    }
};