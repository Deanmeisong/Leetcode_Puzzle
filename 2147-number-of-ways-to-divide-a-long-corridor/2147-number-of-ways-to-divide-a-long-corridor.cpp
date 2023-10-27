using LL = long long;
class Solution {
public:
    LL M = 1e9 + 7;
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<int> pos;
        int count = 0;
        for(int i = 0; i < corridor.size(); ++i) {
            if(corridor[i] == 'S') {
                pos.push_back(i);
                ++count;
            }
        }
        // if(pos.size() == 0) return 0;
        // if(pos.size() % 2 != 0) return 0;
        if(count == 0 || count % 2 != 0) return 0;
        LL res = 1;
        
        for(int i = 2; i < pos.size(); i += 2) {
            res *= (pos[i] - pos[i - 1]);
            res %= M;
        }
        
        return res;
    }
};