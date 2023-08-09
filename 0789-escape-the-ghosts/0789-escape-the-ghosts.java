class Solution {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int[] s = new int[]{0, 0};
        int std = dist(s, target);
        for(int[] g : ghosts) {
            if(dist(g, target) <= std) return false;
        }
        return true;
    }
              
    public int dist(int[] a, int[] b) {
        return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
    }
}