public class Solution {
    public int[] AsteroidCollision(int[] A) {
        Stack<int> st = new Stack<int>();
        foreach(int a in A) {
            int flag = 1;
            while(st.Count > 0 && (st.Peek() > 0 && a < 0)) {
                if(Math.Abs(a) > Math.Abs(st.Peek())) {
                    st.Pop(); continue;
                }
                if(Math.Abs(a) == Math.Abs(st.Peek())) {
                    st.Pop();
                }
                flag = 0;
                break;
            }
            if(flag == 1) st.Push(a);
        }
        int[] ans = new int[st.Count];
        for(int i = st.Count - 1; i >= 0; --i) {
            ans[i] = st.Peek(); st.Pop();
        }
        return ans;

    }
}