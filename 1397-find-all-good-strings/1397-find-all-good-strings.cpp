class Solution {
public:
    int dp[501][51][2][2] = {};
    int kMod = 1e9 + 7;
    int findGoodStrings(int n, string s1, string s2, string evil) {
        return dfs(0, 0, true, true, n, s1, s2, evil, lps(evil));
    }

    int dfs(int i, int emi, bool islb, bool isrb, int n, string s1, string s2, string evil, vector<int> l) {
        if(emi == evil.size()) return 0;
        if(i == n) return 1;
        if(dp[i][emi][islb][isrb] != 0) return dp[i][emi][islb][isrb];
        int res = 0;
        char from = islb ? s1[i] : 'a'; 
        char to = isrb ? s2[i] : 'z';
        for(char c = from; c <= to; ++c) {
            int j = emi;
            while(j > 0 && evil[j] != c) j = l[j - 1];
            if(evil[j] == c) ++j;
            res += dfs(i + 1, j, islb && (c == from), isrb && (c == to), n, s1, s2, evil, l);
            res %= kMod;
        }
        return dp[i][emi][islb][isrb] = res;
    }

    vector<int> lps(string str) {
        int j = 0, n = str.size();
        vector<int> l(n);
        for(int i = 1; i < n; ++i) {
            while(j > 0 && str[i] != str[j]) j = l[j - 1];
            if(str[i] == str[j]) l[i] += ++j;
        }
        return l;
    }
};