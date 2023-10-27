class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<vector<int>> time(n);
        for(int i = 0; i < n; ++i) time[i] = {plantTime[i], -growTime[i]};
        sort(time.begin(), time.end(), [](auto& a, auto& b){return a[1] < b[1];});
        
        int l= 1, r = INT_MAX;
        while(l < r) {
            int m = l + (r - l)/2;
            if(check(m, time)) r = m;
            else l = m + 1;
        }
        
        return l;
     
    }
    
    bool check(int T, vector<vector<int>>& time) {
        int n = time.size();
        int days = 0;
        
        for (int i=0; i<n; i++)
        {
            days += time[i][0];
            
            if (days > T+time[i][1])
            {
                return false;
            }
        }        
        return true;      
//         int days = 0;
//         for(auto t : time) {
//             days += t[0];
//             if(days > T + t[1]) return false;
//         }
        
//         return true;
    }
};