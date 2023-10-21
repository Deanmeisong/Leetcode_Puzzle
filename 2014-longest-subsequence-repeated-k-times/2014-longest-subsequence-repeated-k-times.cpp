class Solution {
    int k;
    string ret;
    string s;
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        this->s = s;
        this->k = k;
        vector<int> count(26);
        for(char c : s) count[c -'a']++;
        string t;
        for(int i =0; i < 26; ++i) {
            if(count[i] >= k) t.push_back(i + 'a');
        }
        string tmp;
        dfs(t, tmp);
        return ret;

    }
    
    void dfs(string& t, string& tmp) {
        if(tmp != "" && !check(tmp)) return;

        if(tmp.size() > ret.size() || (tmp.size() == ret.size() && tmp > ret))
            ret = tmp;
        
        if(tmp.size() > 7) return;
        for(char c : t) {
            tmp.push_back(c);
            dfs(t, tmp);
            tmp.pop_back();
        }
    }
    
    bool check(string& tmp) {
        int j = 0, count = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(tmp[j] != s[i]) continue;
            ++j;
            if(j == tmp.size()) {
                j = 0;
                ++count;
                if(count == k) return true;
            }
        }
        return false;
    }
};