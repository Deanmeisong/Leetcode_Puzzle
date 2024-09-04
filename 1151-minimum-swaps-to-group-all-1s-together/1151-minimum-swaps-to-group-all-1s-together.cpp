class Solution {
public:
    int minSwaps(vector<int>& data) {
        int sum = 0;
        for(int& d : data)
            sum += d;
        int sum_local = 0;
        for(int i = 0; i < sum; ++i)
            sum_local += data[i];
        int ans = sum - sum_local;
        for(int i = sum; i < data.size(); ++i) {
            sum_local -= data[i-sum];
            sum_local += data[i];
            ans = min(ans, sum - sum_local);
        }
        return ans;
    }
};