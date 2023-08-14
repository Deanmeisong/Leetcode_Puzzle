class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] res = new int[temperatures.length];
        Stack<Integer> st = new Stack<>();
        st.push(0);
        
        for(int i = 1; i < temperatures.length; ++i) {
            while(!st.empty() && temperatures[i] > temperatures[st.peek()]) {
                res[st.peek()] = i - st.peek();
                st.pop();
            }
            st.push(i);
        }
        
        return res;
        
    }
}