class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int ends[n];
        int starts[n];
        for(int i=0, s=0; i < n; ++i) {
            s = max(s,0) + arr[i];
            ends[i] = s;
        }
        for(int i=n-1, s=0; ~i; --i) {
            s = max(s,0) + arr[i];
            starts[i] = s;
        }
        int ans = *max_element(ends, ends+n);
        for(int i=1; i<n-1; ++i) {
            ans = max(ans, ends[i-1] + starts[i+1]);
        }
        return ans;
    }
};