class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        int m = sequences.size();
        unordered_map<int, set<int>> h;
        vector<int> degrees(n + 1);
        
        for(int i = 0; i < m; ++i) {
            int len = sequences[i].size();
            for(int j = 1; j < len; ++j) {
                int a = sequences[i][j - 1];
                int b = sequences[i][j];
                if(h.count(a) && h[a].count(b)) continue;
                h[a].insert(b);
                ++degrees[b];
            }
        }
        
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(degrees[nums[i]] == 0) q.push(nums[i]);
        }
        
        while(!q.empty()) {
            if(q.size() > 1) return false;
            auto p = q.front(); q.pop();
            for(int num : h[p]) {
                if(--degrees[num] == 0) q.push(num);
            }
        }
        
        return true;
    }
};