class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diff(length + 1);
        for(auto u : updates) {
            diff[u[0]] += u[2];
            diff[u[1] + 1] -= u[2];
        }
        
        vector<int> res(length);
        int val = 0;
        for(int i = 0; i < length; ++i) {
            val += diff[i];
            res[i] = val;
        }
        return res;
    }
};