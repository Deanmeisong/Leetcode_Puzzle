class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        stack<int> st;
        nums.insert(nums.begin(), 0);
        nums.push_back(0);
        
        for(int i = 0; i < nums.size(); ++i) {
            while(!st.empty() && nums[i] < nums[st.top()]) {
                int h = nums[st.top()];
                st.pop(); 
                int w = i - st.top() - 1;
                if(w * h > threshold) return w;
            }
            st.push(i);
        }
        
        return -1;
    }
};