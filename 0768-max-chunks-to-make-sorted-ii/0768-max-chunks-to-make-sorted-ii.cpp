class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st; int curMax = INT_MIN;
        for(int x : arr) {
            if(st.empty() || st.top() <= x) {
                st.push(x);
                curMax = x;
            } else {
                while(!st.empty() && st.top() > x) {
                    st.pop();
                }
                st.push(curMax);
            }
        }
        return st.size();
    }
};