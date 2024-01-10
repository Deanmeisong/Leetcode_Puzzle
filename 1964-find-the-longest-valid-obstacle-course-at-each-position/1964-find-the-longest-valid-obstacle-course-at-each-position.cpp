class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> arr;
        int n = obstacles.size();
        vector<int> rets;
        
        for(int i = 0; i < n; ++i) {
            if(arr.empty() || arr.back() <= obstacles[i]) {
                arr.push_back(obstacles[i]);
                rets.push_back(arr.size());
            } else {
                auto iter = upper_bound(arr.begin(), arr.end(), obstacles[i]);
                
                *iter = obstacles[i];
                rets.push_back(iter - arr.begin() + 1);
            }
            
        }
        
        return rets;
    }
};