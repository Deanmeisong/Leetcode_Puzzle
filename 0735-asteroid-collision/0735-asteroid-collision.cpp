class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        stack<int> st;
        for(int a : A) {
            int flag = 1;
            while(!st.empty() && (st.top() > 0 && a < 0)) {
                if(abs(a) > abs(st.top())) {
                    st.pop(); continue;
                }
                if(abs(a) == abs(st.top())) {
                    st.pop();
                }
                flag = 0;
                break;
            }
            if(flag) st.push(a);
        }
        
        vector<int> ans(st.size());
        for(int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top(); st.pop();
        }
        
        return ans;
    }
};