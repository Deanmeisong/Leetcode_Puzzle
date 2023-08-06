vector<vector<int>> _nums;
struct cmp {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return _nums[a.first][a.second] > _nums[b.first][b.second];
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        _nums = nums;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int maxV = -1e5; int l = -1e5; int r = 1e5;
        
        for(int i = 0; i < nums.size(); ++i) {
            pq.push({i, 0});
            maxV = max(nums[i][0], maxV);
        }
        
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            if(maxV - nums[p.first][p.second] < r - l) {
                r = maxV;
                l = nums[p.first][p.second];
            }
            if(++p.second >= nums[p.first].size()) break;
            maxV = max(maxV, nums[p.first][p.second]);
            pq.push(p);
        }
        
        return {l, r};
    }
};