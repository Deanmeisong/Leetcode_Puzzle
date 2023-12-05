class Solution {
public:
    vector<vector<int>> colorRed(int n) {
        vector<vector<int>> ans;
        ans.push_back({1, 1});
        for(int i = n, k = 0; i > 1; k = (k + 1) % 4, --i) {
            if(k == 0) {
                for(int j = 1; j < (i << 1); j += 2)
                    ans.push_back({i, j});
            } else if(k == 1) {
                ans.push_back({i, 2});
            } else if(k == 2) {
                for(int j = 3; j < (i << 1); j += 2)
                    ans.push_back({i, j});
            } else if(k == 3) {
                ans.push_back({i, 1});
            }
        }
        return ans;
    }
};