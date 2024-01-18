class Solution {
public:
    vector<int> father;
    int find(int x) {
        if(x != father[x]) father[x] = find(father[x]);
        return father[x];
    }
    void un(int x, int y) {
        x = father[x]; y = father[y];
        if(x < y) father[x] = y;
        else father[y] = x;
    }
    
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        father.resize(n);
        vector<bool> rets;
        for(int i = 0; i < n; ++i) father[i] = i;
        for(auto const& req : requests) {
            int flag = 1;
            int u = req[0], v = req[1];
            int uf = find(u), vf = find(v);
            if(uf == vf) {
                rets.push_back(true);
                continue;
            }
            
            for(auto const& res : restrictions) {
                int x = res[0], y = res[1];
                int xf = find(x), yf = find(y);
                if((xf == uf && yf == vf) || (xf == vf && yf == uf)) {
                    flag = 0;
                    break;
                }
            }
            
            rets.push_back(flag);
            if(flag) un(uf, vf);
        }
        return rets;
    }
};