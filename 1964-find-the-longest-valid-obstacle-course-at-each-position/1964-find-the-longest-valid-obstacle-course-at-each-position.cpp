class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> arr;
        int n = obstacles.size();
        vector<int> rets(n);
        
        for(int i = 0; i < n; ++i) {
            if(arr.empty() || arr.back() <= obstacles[i]) {
                arr.push_back(obstacles[i]);
                rets[i] = arr.size();
            } else {
                auto iter = upper_bound(arr.begin(), arr.end(), obstacles[i]);
                
                *iter = obstacles[i];
                rets[i] = iter - arr.begin() + 1;
            }
            
        }
        
        return rets;
    }
};