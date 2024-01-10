class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> arr;
        int n = obstacles.size();
        vector<int> rets;
        
        for(int x : obstacles) {
            if(arr.empty() || arr.back() <= x) {
                arr.push_back(x);
                rets.push_back(arr.size());
            } else {
                auto iter = upper_bound(arr.begin(), arr.end(), x);
                
                *iter = x;
                rets.push_back(iter - arr.begin() + 1);
            }
            
        }
        
        return rets;
    }
};