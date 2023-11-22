class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> st1; stack<int> st2;
        
        for(int i = 0; i < n; ++i) {
            while(!st2.empty() && nums[st2.top()] < nums[i]) {
                ret[st2.top()] = nums[i];
                st2.pop();
            }
            vector<int> tmp;
            while(!st1.empty() && nums[st1.top()] < nums[i]) {
                tmp.push_back(st1.top());
                st1.pop();
            }
            reverse(tmp.begin(), tmp.end());
            for(int t : tmp) {
                st2.push(t);
            }
            st1.push(i);
        }
        
        return ret;
    }
};