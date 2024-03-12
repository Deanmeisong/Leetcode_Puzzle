using LL = long long;
class Solution {
public:
    unordered_set<LL> Set;
    unordered_map<int, vector<int>> Map;
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int ret = 0;
        int n = word.size();
        int right = n;
        for(string f : forbidden) {
            LL code = 0;
            for(char c : f) 
                code = (code<<5) + (c - 'a' + 1);
            Set.insert(code);
        }

        for(int len = 1; len <= 10; ++len)
            helper(word, len);
        for(int i = n - 1; i >= 0; --i) {
            if(Map.find(i) != Map.end()) {
                for(auto j : Map[i]) {
                    right = min(right, j);
                }
            }
            ret = max(ret, right - i);
        }

        return ret;
    }
    
    void helper(string word, int len) {
        int n = word.size();
        LL code = 0;
        for(int i = 0; i < n; ++i) {
            if(i >= len)
                code &= (1LL<<(5*(len-1))) - 1;
            code = (code<<5) + word[i] - 'a' + 1;
            if(i >= len - 1 && Set.find(code) != Set.end())
                Map[i-len+1].push_back(i);
        }
    }
};