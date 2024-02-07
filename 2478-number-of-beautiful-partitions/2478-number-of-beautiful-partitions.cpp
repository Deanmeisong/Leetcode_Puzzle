using LL = long long;
class Solution {
public:
    LL dp[1005][1005];
    LL M = 1e9 + 7;
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.length();
        // s.insert(s.begin(), '#');
        s = "#" + s;
        dp[0][0] = 1;
        
        for(int j = 1; j <= k; ++j) {
            LL presum = 0;
            for(int i = 1; i <= n; ++i) {
                if(i - minLength + 1 >= 1 && isPrime(s[i - minLength + 1]) && !isPrime(s[i - minLength])) {
                    presum += dp[i - minLength][j - 1];
                    presum %= M;
                }
                
                if(!isPrime(s[i])) dp[i][j] = presum;
            }
        }
        
        return dp[n][k];
        
    }
    
    bool isPrime(char ch) {
        return ch == '2' || ch == '3' || ch == '5' || ch == '7';
    }
};