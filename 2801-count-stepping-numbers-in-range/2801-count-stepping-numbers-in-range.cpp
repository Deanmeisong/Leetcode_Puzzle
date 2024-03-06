using LL = long long;
class Solution {
public:
    LL M = 1e9 + 7;
    int countSteppingNumbers(string low, string high) {
        LL ret = (helper(high) - helper(low) + M) % M;
        ret = (ret + (check(low))) % M;
        return ret;
    }
    bool check(string s) {
        int n = s.length();
        for(int i = 0; i < n - 1; ++i)
            if(abs(s[i] - s[i+1]) != 1) return false;
        return true;
    }
    LL helper(string num) {
        LL ret = 0;
        int n = num.length();
        int memo[105][10][2];
        memset(memo, -1, sizeof(memo));
        for(int len = 1; len < n; ++len) {
            for(int d = 1; d <= 9; ++d) {
                ret = (ret + dfs(len-1, d, false, num, memo)) % M;
            }
        }
        int D = num[0] - '0';
        for(int d = 1; d < D; ++d) ret = (ret + dfs(n-1, d, false, num, memo)) % M;
        ret = (ret + dfs(n-1, D, true, num, memo)) % M;
        return ret;
    }
    
    int dfs(int len, int prev, bool isSame, string num, int memo[105][10][2]) {
        if(len == 0) return 1;
        if(memo[len][prev][isSame] != -1) return memo[len][prev][isSame];
        LL ret = 0;
        int n = num.length();

        if(!isSame) {
            if(prev+1 <= 9) ret = (ret + dfs(len-1, prev+1, false, num, memo))%M;
            if(prev-1 >= 0) ret = (ret + dfs(len-1, prev-1, false, num, memo))%M;
        } else {
            int D = num[n - len] - '0';
            if(prev+1 < D) ret = (ret + dfs(len-1, prev+1, false, num, memo))%M;
            else if(prev+1 == D) ret = (ret + dfs(len-1, prev+1, true, num, memo))%M;
            if(prev-1 >= 0 && prev-1 < D) ret = (ret + dfs(len-1, prev-1, false, num, memo))%M;
            else if(prev-1 >= 0 && prev-1 == D) ret = (ret + dfs(len-1, prev-1, true, num, memo))%M;              
        }
        return memo[len][prev][isSame] = ret;
    }

};