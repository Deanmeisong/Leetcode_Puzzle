class Solution {
    public int[] getModifiedArray(int length, int[][] updates) {
        int[] diff = new int[length + 1];
        for(int[] x : updates) {
            diff[x[0]] += x[2];
            diff[x[1] + 1] -= x[2];
        }
        int val = 0;
        int[] res = new int[length];
        
        for(int i = 0; i < length; ++i) {
            val += diff[i];
            res[i] = val;
        }
        
        return res;
    }
}