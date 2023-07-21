class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<int> nums(n, -1);
        for(auto e : edges) {
            int x = find(nums, e[0]);
            int y = find(nums, e[1]);
            if(x == y) return false;
            nums[x] = y;
        }
        return true;
    }
    
    int find(vector<int> nums, int i) {
        if(nums[i] == -1) return i;
        return find(nums, nums[i]);
    }
};