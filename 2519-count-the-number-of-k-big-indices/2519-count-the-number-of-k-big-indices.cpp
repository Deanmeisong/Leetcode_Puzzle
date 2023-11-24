class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        vector<bool> check(n);
        for(int i = 0; i < n; ++i) {
            if(pq.size() == k and nums[i] > pq.top()) check[i] = true;
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
        int res = 0;
        priority_queue<int> pq1;
        for(int i = n - 1; i >= 0; --i) {
            if(pq1.size() == k and nums[i] > pq1.top() and check[i]) {
                res++;
            }
            pq1.push(nums[i]);
            if(pq1.size() > k) pq1.pop();
        }
        return res;
    }
};