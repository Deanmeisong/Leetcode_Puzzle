class Solution {
public:
    vector<int> lcs(vector<int>& s) {
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        for(int i = 1; i < n; ++i) {
            int j = dp[i - 1];
            while(j > 0 && s[i] != s[j]) j = dp[j-1];
            dp[i] = j + (s[i] == s[j]);
        }
        return dp;
    };
    
    int countMatchingSubarrays(vector<int>& s, vector<int>& pattern) {
        for(int i=0;i<s.size()-1;i++)
        {
            int a = s[i];
            int b = s[i+1];
            
            if(a<b)
                s[i] = 1;
            if(a == b)
                s[i] = 0;
            if(a>b)
                s[i] = -1;
           
        } //convert s[i] to {-1,0,1}
        vector<int> ns(pattern);
        ns.push_back(4);
        for(int x : s) ns.push_back(x);
        vector<int> dp = lcs(ns);
        int count = 0;
        for(int i = 0; i < dp.size(); ++i)
            if(dp[i] == pattern.size()) ++count;
        return count;
    }
};