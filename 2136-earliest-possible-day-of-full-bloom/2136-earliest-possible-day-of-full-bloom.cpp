class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<vector<int>> time(n);
        for(int i = 0; i < n; ++i) time[i] = {plantTime[i], growTime[i]};
        sort(time.begin(), time.end(), [](auto& a, auto& b){return a[1] > b[1];});
        
        int ret = 0, days = 0;
        for(auto t : time) {
            days += t[0];
            ret = max(ret, days + t[1]);
        }
        
        return ret;
    }
};