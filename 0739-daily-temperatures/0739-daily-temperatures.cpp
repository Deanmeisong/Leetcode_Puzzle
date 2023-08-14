class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& ts) {
        vector<int> res(ts.size());
        stack<pair<int, int>> st;
        for(int i = 0; i < ts.size(); ++i) {
            if(st.empty() || ts[i] <= st.top().first) {
                st.push({ts[i], i});
                continue;
            }
            else {
                while(!st.empty() and ts[i] > st.top().first) {
                    auto p = st.top(); st.pop();
                    res[p.second] = i - p.second;
                }
                st.push({ts[i], i});
            }
        }
        
        return res;
    }
};