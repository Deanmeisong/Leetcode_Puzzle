class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> res(n, 0);
        
        for(int i = n - 1; i >= 0; --i) {
            int count = 0;
            while(!st.empty() && heights[i] > heights[st.top()]) {
                ++count;
                st.pop();
            }
            
            if(!st.empty()) ++count;
            
            res[i] = count;
            st.push(i);
        }
        
        return res;
    }
};