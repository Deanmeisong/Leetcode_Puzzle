class Solution {
public:
    int ret = 0;
    int countSpecialNumbers(int N) {
        string s = to_string(N);
        int n = s.length();
        for(int len = 1; len < n; ++len)
            ret += A(10, len) - A(9, len-1);
        vector<int> visited(10, 0);
        dfs(0, s, visited);
        return ret;
    }
    
    void dfs(int i, string s, vector<int>& visited) {
        int n = s.length();
        if(i >= n) {
            ret += 1; return;
        }
        
        for(int d = 0; d <= 9; ++d) {
            if(d == 0 && i == 0) continue;
            if(visited[d] == 1) continue;
            if(d < s[i] - '0') ret += A(10-i-1, n-i-1);
            else if(d == s[i] - '0') {
                visited[d] = 1;
                dfs(i+1, s, visited);
                visited[d] = 0;
            }
        }
        
    }
    
    int A(int m, int x) {
        if(x == 0) return 1;
        int ans = 1;
        for(int i = 0; i < x; ++i) ans = ans*(m-i);
        return ans;
    }
};