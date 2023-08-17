class Solution {
    public int shortestSequence(int[] rolls, int k) {
        HashSet<Integer> s = new HashSet<>();
        int res = 1;
        for(int i : rolls) {
            s.add(i);
            if(s.size() == k) {
                s.clear(); ++res;
            }
        }
        return res;
    }
}