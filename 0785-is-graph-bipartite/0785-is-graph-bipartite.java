class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length; int[] colors = new int[n];
        for(int i = 0; i < n; ++i) {
            if(colors[i] == 0 && !dfs(graph, colors, i, 1)) return false;
        }
        return true;
    }
    
    public boolean dfs(int[][] g, int[] colors, int i, int color) {
        colors[i] = color;
        for(int j = 0; j < g[i].length; ++j) {
            int k = g[i][j];
            if(colors[k] == -color) continue;
            if(colors[k] == color || !dfs(g, colors, k, -color)) return false;
        }
        return true;
    }
}