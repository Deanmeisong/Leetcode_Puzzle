class Solution {
public:
    vector<int> records[51];
    vector<int> path;
    int visited[100001];
    vector<int> nums;
    vector<int> next[100001];
    vector<int> rets;
    
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        this->nums = nums;
        int n = nums.size(); rets.resize(n);
        for(auto e : edges) {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        visited[0] = 1;
        dfs(0, 0);
        return rets;
    }
    
    void dfs(int idx, int depth) {
        int i = -1;
        for(int d = 1; d <= 50; ++d) {
            if(records[d].size() > 0 && gcd(nums[idx], d) == 1) {
                i = max(i, records[d].back());
            }
        }
        
        rets[idx] = (i == -1) ? -1 : path[i];
        path.push_back(idx);
        records[nums[idx]].push_back(depth);
        
        for(int j : next[idx]) {
            if(visited[j]) continue;
            visited[j] = 1;
            dfs(j, depth + 1);
            visited[j] = 0;
        }
        
        path.pop_back();
        records[nums[idx]].pop_back();
        
    }
};