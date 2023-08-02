class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> roots(n);
        for(int i = 0; i < n; ++i) roots[i] = i;
        function<int(int)> find = [&](int x) {
            while(roots[x] != x) {
                roots[x] = roots[roots[x]];
                x = roots[x];
            }
            return x;
        };
        
        for(auto e : edges) {
            int r1 = find(e[0]); int r2 = find(e[1]);
            if(r1 != r2) {
                roots[r1] = r2;
                --n;
            }
        }
        
        return n;
        
    }
};