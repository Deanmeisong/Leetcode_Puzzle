typedef pair<int, int> PII;
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ret(queries.size(), -1);
        vector<PII> qs;
        for(int i = 0; i < queries.size(); ++i) {
            qs.push_back({queries[i], i});
        }
        sort(intervals.begin(), intervals.end());
        sort(qs.begin(), qs.end());
        
        priority_queue<PII, vector<PII>, greater<>> pq;
        int i = 0;
        
        for(auto p : qs) {
            auto [t, idx] = p;
            
            while(i < intervals.size() && intervals[i][0] <= t) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                ++i;
            }
            
            while(!pq.empty() and pq.top().second < t)
                pq.pop();
            
            if(!pq.empty()) ret[idx] = pq.top().first;
        }
        
        return ret;
    }
};