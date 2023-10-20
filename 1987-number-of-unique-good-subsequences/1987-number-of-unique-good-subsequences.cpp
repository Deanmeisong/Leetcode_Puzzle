using LL = long long;
class Solution {
LL M = 1e9 + 7;
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int n = binary.size();
        string s = "#" + binary;
        vector<LL>dp(n+1,0);
        int m = 1;
        while(m <=n &&  s[m] == '0') ++m;
        if (m == n+1) return 1;
        dp[m] = 1;

        
        int last0 = 0, last1 = 0;
        
        for(int i = m + 1; i <= n; ++i) {
            int j = (s[i] == '0') ? last0 : last1;
            dp[i] = 2 * dp[i - 1] - (j>=1 ? dp[j-1]:0);   
            dp[i] = (dp[i] + M) % M;;
            
            if(s[i] == '0') last0 = i;
            else last1 = i;
        } 
        
 
        return dp[n] + (binary.find("0") != -1);

    }
};