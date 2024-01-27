class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> Map;
        for(const auto& f : flowers) {
            ++Map[f[0]];
            --Map[f[1] + 1];
        }
        vector<pair<int, int>> diff(Map.begin(), Map.end());
        sort(diff.begin(), diff.end());
        
        vector<pair<int, int>> ps;
        for(int i = 0; i < people.size(); ++i) ps.push_back({people[i], i});
        
        sort(ps.begin(), ps.end());
        vector<int> ret(people.size());
        int sum = 0;
        int j = 0;
        
        for(int i = 0; i < ps.size(); ++i) {
            while(j < diff.size() && diff[j].first <= ps[i].first) {
                sum += diff[j].second;
                ++j;
            }
            ret[ps[i].second] = sum;
        }
        return ret;
        
    }
};