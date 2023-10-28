using LL = long long;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<LL> left(3 * n);
        priority_queue<int> ql;
        LL sum = 0;
        for(int i = 0; i < 3 * n; ++i) {
            sum += nums[i];
            ql.push(nums[i]);
            if(ql.size() > n) {
                sum -= ql.top();
                ql.pop();
            }
            left[i] = sum;
        }
        
        sum = 0;
        vector<LL> right(3 * n);
        priority_queue<int, vector<int>, greater<>> qr;
        for(int i = 3 * n - 1; i >= 0; --i) {
            sum += nums[i];
            qr.push(nums[i]);
            if(qr.size() > n) {
                sum -= qr.top();
                qr.pop();
            }
            right[i] = sum;
        }
        
        LL ret = LLONG_MAX;
        for(int i = n - 1; i < 2 * n; ++i) ret = min(ret, left[i] - right[i + 1]);
        
        return ret;
    }
};