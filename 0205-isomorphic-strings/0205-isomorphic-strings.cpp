class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> ms; unordered_map<int, int> mt;
        for(int i = 0; i < s.length(); ++i) {
            if(ms[s[i]] and ms[s[i]] != t[i]) return false;
            if(mt[t[i]] and mt[t[i]] != s[i]) return false;
            ms[s[i]] = t[i];
            mt[t[i]] = s[i]; 
        }
        return true;
    }
};