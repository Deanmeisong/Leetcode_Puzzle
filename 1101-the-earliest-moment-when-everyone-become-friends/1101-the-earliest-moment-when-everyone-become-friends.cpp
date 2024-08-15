class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        vector<int> parents(n);
        function<int(int)> find = [&](int x) {
            if(x != parents[x]) parents[x] = find(parents[x]);
            return parents[x];
        };
        for(int i = 0; i < n; ++i)
            parents[i] = i;
        for(auto log: logs) {
            int x = find(log[1]);
            int y = find(log[2]);
            if (x != y) {
                parents[x] = y;
                --n;
            }
            if(n == 1) return log[0];
        }
        return -1;
        
    }
    
};