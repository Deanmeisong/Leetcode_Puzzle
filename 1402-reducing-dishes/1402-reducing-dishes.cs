public class Solution {
    public int MaxSatisfaction(int[] satisfaction) {
        Array.Sort(satisfaction);
        int n = satisfaction.Length;
        int res = 0, tmp = 0;
        for(int i = n - 1; i >= 0 && satisfaction[i] + tmp > 0; --i) {
            tmp += satisfaction[i];
            res += tmp;
        }
        return res;
    }
}