class Solution {
    
    public int countComponents(int n, int[][] edges) {
        int[] roots = new int[n];
        for(int i = 0; i < n; ++i) roots[i] = i;
        for(int[] e : edges) {
            int r1 = find(roots, e[0]); int r2 = find(roots, e[1]);
            if(r1 != r2) {
                roots[r1] = r2;
                --n;
            }
        }
        return n;
    }
    
    int find(int[] roots, int x) {
        while(x != roots[x]) {
            roots[x] = roots[roots[x]];
            x = roots[x];
        }
        return x;
    }
}