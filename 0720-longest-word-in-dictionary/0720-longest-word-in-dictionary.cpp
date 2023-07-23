class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        string res;
        unordered_set<string> built;
        
        for(string w : words) {
            if(w.size() == 1 or built.count(w.substr(0, w.length() - 1))) {
                if(w.size() > res.size()) res = w;
                built.insert(w);
            }
        }
        
        return res;
    }
};