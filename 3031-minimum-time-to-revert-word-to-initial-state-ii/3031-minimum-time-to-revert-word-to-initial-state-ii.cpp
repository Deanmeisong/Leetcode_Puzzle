class Solution {
public:
    int minimumTimeToInitialState(string word, int k) 
    {
        vector<int> next = lcs(word);
        int n = word.length();
        int len = next[n - 1];
        while(len > 0 && (n-len)%k != 0) len = next[len - 1];
        if(len == 0) {
            if(n%k == 0) return n/k;
            else return n/k + 1;
        } else {
            return (n-len)/k;
        }
    }
    
    vector<int> lcs(string s) {
        int n = s.length();
        vector<int> dp(n);
        dp[0] = 0;
        int j = 0;
        for(int i = 1; i < n; ++i) {
            j = dp[i-1];
            while(j >= 1 && s[j] != s[i]) j = dp[j - 1];
            dp[i] = j + (s[i] == s[j]);
        }
        return dp;
    }
};