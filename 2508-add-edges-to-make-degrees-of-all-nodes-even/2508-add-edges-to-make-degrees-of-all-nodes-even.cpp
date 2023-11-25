class Solution {
public:
    set<int> next[100005];
    bool isPossible(int n, vector<vector<int>>& edges) {
        for(auto& e : edges) {
            next[e[0]].insert(e[1]);
            next[e[1]].insert(e[0]);
        }
        vector<int> odds;
        for(int i = 1; i <= n; ++i)
            if(next[i].size()& 1) odds.push_back(i);
        
        if(odds.size() == 0) return true;
        if(odds.size() == 2) {
            int a = odds[0]; int b = odds[1];
            if(next[a].find(b) == next[a].end()) return true;
            else for(int i = 1; i <= n; ++i) {
                if(i == a || i == b) continue;
                if(next[i].find(a) == next[i].end() && next[i].find(b) == next[i].end()) return true;
            }
            return false;
        }
        if(odds.size() == 4) {
            int a = odds[0]; int b = odds[1]; int c = odds[2]; int d = odds[3];
            if(next[a].find(b) == next[a].end() && next[c].find(d) == next[c].end()) return true;
            if(next[a].find(c) == next[a].end() && next[b].find(d) == next[b].end()) return true;
            if(next[a].find(d) == next[a].end() && next[c].find(b) == next[c].end()) return true;
            return false;
        }
        return false;
    }
};