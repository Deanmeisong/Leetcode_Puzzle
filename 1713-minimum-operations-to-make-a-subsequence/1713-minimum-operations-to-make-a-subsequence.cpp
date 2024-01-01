class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> m;
        int n = target.size();
        
        for(int i = 0; i < n; ++i) m[target[i]] = i;
        vector<int> dp;
        for(int x : arr) {
            auto idx = m.find(x);
            if(idx == m.end()) continue;
            int id = idx->second;
            if(dp.empty() || id > dp.back()) dp.push_back(id);
            else *lower_bound(dp.begin(), dp.end(), id) = id;
        }
        
        return n - dp.size();
    }
};