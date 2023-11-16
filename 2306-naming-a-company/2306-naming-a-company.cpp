using LL = long long;
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> h2str(26);
        for(string ide : ideas) h2str[ide[0] - 'a'].insert(ide.substr(1));
        
        LL ret = 0;
        for(int i = 0; i < 26; ++i)
            for(int j = i + 1; j < 26; ++j) {
                int dup = 0;
                for(string str : h2str[i]) {
                    if(h2str[j].find(str) != h2str[j].end()) ++dup;
                }
                
                LL a = h2str[i].size() - dup;
                LL b = h2str[j].size() - dup;
                
                ret += 2 * a * b;
            }
        return ret;
    }
};