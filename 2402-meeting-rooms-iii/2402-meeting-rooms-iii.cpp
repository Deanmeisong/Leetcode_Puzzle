using LL = long long;
using PLI = pair<LL, int>;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<>> free;
        priority_queue<PLI, vector<PLI>, greater<>> busy;
        sort(meetings.begin(), meetings.end());
        vector<LL> count(n);
        for (int i=0; i<n; i++) free.push(i);
        
        for(int i = 0; i < meetings.size(); ++i) {
            LL start = meetings[i][0]; LL end =  meetings[i][1];
            while(!busy.empty() && busy.top().first <= start) {
                free.push(busy.top().second);
                busy.pop();
            }
            
            if(!free.empty()) {
                int idx = free.top();
                free.pop();
                busy.push({end, idx});
                ++count[idx];
            } else {
                auto[bs, idx] = busy.top();
                busy.pop();
                busy.push({bs + end - start, idx});
                ++count[idx];
            }
        }
        
        return max_element(count.begin(), count.end()) - count.begin();
    }
};