using LL = long long;
LL M = 1e9 + 7;
class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        LL ret = (helper(num2, max_sum) - helper(num2, min_sum-1) + M)%M - (helper(num1, max_sum) - helper(num1, min_sum-1) + M)%M;
        ret = (ret + M)%M;
        int Num1 = strToInt(num1);
        if(Num1 >= min_sum && Num1 <= max_sum) ret = (ret+1)%M;
        return ret;
    }
    
    int strToInt(string num) {
        int ans = 0;
        for(char c : num) ans += c - '0';
        return ans;
    }
    
    int helper(string num, int max_sum) {
        vector<vector<vector<int>>> memo(2, vector<vector<int>>(25, vector<int>(405, -1)));
        return dfs(num, max_sum, 0, 0, true, memo);
    }
    
    int dfs(string num, int max_sum, int i, int sum, bool isSame, vector<vector<vector<int>>>& memo) {
        if(max_sum < sum) return 0;
        if(memo[isSame][i][sum] != -1) return memo[isSame][i][sum];
        if(i == num.length()) return 1;
        LL ret = 0;
        if(!isSame) {
            for(int k = 0; k <= 9; ++k) {
                ret += dfs(num, max_sum, i+1, sum+k, false, memo);
                ret %= M;
            }
        }
     else 
       {
            for(int k = 0; k < (num[i] - '0'); ++k) {
                ret += dfs(num, max_sum, i+1, sum+k, false, memo);
                ret %= M;
            }
            ret += dfs(num, max_sum, i+1, sum+(num[i]-'0'), true, memo);
            ret %= M;
        }

        memo[isSame][i][sum] = ret;
        return ret;
    }
    
};