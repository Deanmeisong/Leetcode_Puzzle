using LL = long long;
class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        vector<LL> dp(n);
        stack<int> st;
        LL ret = 0;
        
        for(int i = 0; i < n; ++i) {
            
            while(!st.empty() && books[st.top()] > books[i] - (i - st.top())) st.pop();
            if(!st.empty()) {
                int j = st.top();
                int L = i - j;
                dp[i] = dp[j] + ((LL)books[i] + (LL)books[i] - L + 1) * L / 2;
            } else {
                int L = min(i + 1, books[i]);
                dp[i] = ((LL)books[i] + (LL)books[i] - L + 1) * L / 2;
            }
            ret = max(ret, dp[i]);
            st.push(i);
        }
        
        return ret;
    }
};