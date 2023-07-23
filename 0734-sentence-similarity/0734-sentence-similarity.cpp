class Solution {
public:
    bool areSentencesSimilar(vector<string>& s1, vector<string>& s2, vector<vector<string>>& sim) {
        if(s1.size() != s2.size()) return false;
        map<string, set<string>> sm;
        for(auto si : sim) {
            sm[si[0]].insert(si[1]);
            sm[si[1]].insert(si[0]);
        }
        for(int i = 0; i < s1.size(); ++i) {
            if(s1[i] != s2[i] and !sm[s1[i]].count(s2[i]) and !sm[s2[i]].count(s1[i])) return false; 
        }
        return true;
    }
};