public class Solution {
    public int[] MaxDepthAfterSplit(string seq) {
        int n = seq.Length;
        int[] ans = new int[n];
        for(int i=0, x=0; i < n; ++i) {
            if(seq[i] == '(') ans[i] = ++x & 1;
            else ans[i] = x-- & 1;
        }
        return ans;
    }
}