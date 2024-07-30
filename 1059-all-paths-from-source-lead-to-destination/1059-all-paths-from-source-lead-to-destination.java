class Solution {
    public boolean leadsToDestination(int n, int[][] edges, int source, int destination) {
        if(edges.length == 0 && source == destination) return true;
        if(edges.length == 0 && source != destination) return false;
        List<Integer>[] g = new List[n];
        int[] colors = new int[n];
        buildGraph(g, edges);
        return dfs(g, source, destination, colors);
    }
    
    void buildGraph(List<Integer>[] g, int[][] edges) {
        for(int[] e : edges) {
            int from = e[0]; int to = e[1];
            if(g[from] == null) g[from] = new LinkedList<>();
            g[from].add(to);
        }
    }
    
    boolean dfs(List<Integer>[] g, int source, int destination, int[] colors) {
        if(g[source] == null || g[source].size() == 0) return source == destination;
        colors[source] = 1;
        for(int nxt : g[source]) {
            if(colors[nxt] == 1) return false;
            if(colors[nxt] == 0 && !dfs(g, nxt, destination, colors)) return false;
        }
        colors[source] = 2;
        return true;
    }
}