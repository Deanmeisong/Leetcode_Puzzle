class Solution {
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        List<List<Integer>> res = new ArrayList<>();
        Map<Integer, Set<Integer>> m = new HashMap<>();
        build(connections, m);
        int[] ids= new int[n];
        Arrays.fill(ids, -1);
        dfs(0, 0, -1, ids, res, m);
        return res;
    }
    
    int dfs(int node, int nodeID, int par, int[] ids, List<List<Integer>> res, Map<Integer, Set<Integer>> m) {
        ids[node] = nodeID;
        Set<Integer> neighors = m.get(node);
        for(int neigh : neighors) {
            if(neigh == par) continue;
            else if(ids[neigh] == -1) ids[node] = Math.min(ids[node], dfs(neigh, nodeID + 1, node, ids, res, m));
            else ids[node] = Math.min(ids[node], ids[neigh]);
        }
        
        if(ids[node] == nodeID && node != 0) res.add(Arrays.asList(par, node));
        return ids[node];
    }
    
    void build(List<List<Integer>> connections, Map<Integer, Set<Integer>> m) {
        for(List<Integer> c : connections) {
            int u = c.get(0); int v = c.get(1);
            Set<Integer> uNeighors = m.getOrDefault(u, new HashSet<Integer>());
            Set<Integer> vNeighors = m.getOrDefault(v, new HashSet<Integer>());
            uNeighors.add(v);
            vNeighors.add(u);
            m.put(u, uNeighors);
            m.put(v, vNeighors);
        }
    }
}