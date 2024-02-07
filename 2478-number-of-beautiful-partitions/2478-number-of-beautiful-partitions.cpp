using LL = long long;
class Solution {
public:
    LL dp[1005][1005];
    LL M = 1e9 + 7;
    int beautifulPartitions(string s, int K, int minLength) {
        int n = s.length();
        s.insert(s.begin(), '#');
        // s = "#" + s;
        dp[0][0] = 1;
        
        for (int i=1; i<=n; i++)
            for (int j=1; j<=K; j++)
            {
                if (isPrime(s[i])) {
                    continue;
                }
                for (int k=j; (k+minLength-1)<=i; k++)
                {
                    if (isPrime(s[k]))
                        dp[i][j] = (dp[i][j] + dp[k-1][j-1]) % M;
                }
            }

        return dp[n][K];
        
    }
    
    bool isPrime(char ch) {
        return ch == '2' || ch == '3' || ch == '5' || ch == '7';
    }
};