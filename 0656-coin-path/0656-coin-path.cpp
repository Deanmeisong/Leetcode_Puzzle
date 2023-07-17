class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        vector<int> ans;
        int n = A.size();
        if(A.size() == 0 || A.back() == -1) return ans;
        vector<int> dp(n, INT_MAX), pos(n, -1);
        dp[n - 1] = A[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            if(A[i] == -1) continue;
            for(int j = i + 1; j <= min(B + i, n - 1); ++j) {
                if(dp[j] == INT_MAX) continue;
                if(dp[j] + A[i] < dp[i]) {
                    dp[i] = dp[j] + A[i];
                    pos[i] = j;
                }
            }
        }
        
        if(dp[0] == INT_MAX) return ans;
        int k = 0;
        while(k != -1) {
            ans.push_back(k + 1);
            k = pos[k];
        }
        return ans;
    }
};