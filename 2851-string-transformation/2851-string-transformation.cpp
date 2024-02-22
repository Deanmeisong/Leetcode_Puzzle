using LL = long long;
class Solution {
public:
    LL M = 1e9 + 7;
    int numberOfWays(string s, string t, long long k) {
        string ss = s + s;
        ss.pop_back();
        int p = strStr(ss, t);
        int n = s.size();
        vector<LL> T = {n - 1 - p, n - p, p, p - 1};
        vector<LL> Tk = quickMul(T, k);
        
        if(t == s) return Tk[3];
        return Tk[2];   
    }
    
    
    vector<LL> multiply(vector<LL> mat1, vector<LL> mat2) {
        LL a1 = mat1[0], b1 = mat1[1], c1 = mat1[2], d1 = mat1[3];
        LL a2 = mat2[0], b2 = mat2[1], c2 = mat2[2], d2 = mat2[3];
        return {(a1*a2+b1*c2)%M, (a1*b2+b1*d2)%M, (c1*a2+d1*c2)%M, (c1*b2+d1*d2)%M};
    }
    
    vector<LL> quickMul(vector<LL> mat, LL N) {
        if(N == 0) return {1, 0, 0, 1};
        vector<LL> mat2 = quickMul(mat, N/2);
        if(N % 2 == 0) return multiply(mat2, mat2);
        return multiply(multiply(mat2, mat2), mat);
      
    }
    
    int strStr(string hay, string needle) {
        int m = needle.size();
        int n = hay.size();
        vector<int> suf = preprocess(needle);
        vector<int> dp(n, 0);
        dp[0] = (hay[0] == needle[0]);
        int count = 0;
        if(m == 1 && dp[0] == 1) count++;
        for(int i = 1; i < n; ++i) {
            int j = dp[i - 1];
            while(j > 0 && needle[j] != hay[i]) j = suf[j - 1];
            dp[i] = j + (needle[j] == hay[i]);
            if(dp[i] == m) ++count;
        }
        return count;
      
    }
    
    vector<int> preprocess(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        for(int i = 1; i < n; ++i) {
            int j = dp[i - 1];
            while(j > 0 && s[j] != s[i]) j = dp[j - 1];
            dp[i] = j + (s[i] == s[j]);
        }
        return dp;
              
    }
};