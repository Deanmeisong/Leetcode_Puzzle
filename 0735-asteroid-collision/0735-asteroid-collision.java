class Solution {
    public int[] asteroidCollision(int[] A) {
        Stack<Integer> st = new Stack<>();
        for (int a : A) {
            int flag = 1;
            while (!st.empty() && (st.peek() > 0 && a < 0)) {
                if (Math.abs(a) > Math.abs(st.peek())) {
                    st.pop();
                    continue;
                }
                if (Math.abs(a) == Math.abs(st.peek())) {
                    st.pop();
                }
                flag = 0;
                break;
            }
            if (flag == 1) {
                st.push(a);
            }
        }
        int[] ans = new int[st.size()];
        for (int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.peek();
            st.pop();
        }
        return ans;
    }
}