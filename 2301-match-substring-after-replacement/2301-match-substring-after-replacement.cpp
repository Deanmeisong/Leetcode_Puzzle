class Solution {
public:
    bool table[256][256];
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        for(auto x : mappings) table[x[0]][x[1]] = true;
        int m = s.size();
        for(int i = 0; i < m; ++i) {
            bool flag = true;
            for(int j = 0; j < sub.size(); ++j) {
                if (i+j<m && (sub[j]==s[i+j] || table[sub[j]][s[i+j]])) continue;
                flag = false;
            }
            if(flag == true) return true;
        }
        return false;
    }
};