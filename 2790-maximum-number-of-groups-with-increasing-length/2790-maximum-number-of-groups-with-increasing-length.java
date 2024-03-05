class Solution {
    public int maxIncreasingGroups(List<Integer> A) {
        Collections.sort(A);
        long tt = 0, ans = 0;
        for(int a : A) {
            tt += a;
            if(tt >= (ans+1)*(ans+2)/2) ++ans;
        }
        return (int)ans;
    }
}