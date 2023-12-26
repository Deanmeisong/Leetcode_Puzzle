class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> Map;
        for(int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            Map[s].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto [k, v] : Map) {
            ans.push_back({});
            for(int i : v) {
                ans.back().push_back(strs[i]);
            }
        }
        return ans;
    }
};