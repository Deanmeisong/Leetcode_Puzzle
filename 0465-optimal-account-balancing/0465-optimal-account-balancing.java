class Solution {
    public int minTransfers(int[][] transactions) {
        HashMap<Integer, Integer> m = new HashMap<>();
        for(int[] t : transactions) {
            m.put(t[0], m.getOrDefault(t[0], 0) + t[2]);
            m.put(t[1], m.getOrDefault(t[1], 0) - t[2]);
        }
        
        ArrayList<Integer> list = new ArrayList();
        for(int v : m.values()) {
            list.add(v);
        }
        
        return dfs(0, list);
    }
    
    public int dfs(int k, List<Integer> list) {
        if(k == list.size()) return 0;
        int cur = list.get(k);
        if(cur == 0) return dfs(k + 1, list);
        int minV = Integer.MAX_VALUE;
        for(int i = k + 1; i < list.size(); ++i) {
            int next = list.get(i);
            if(cur * next < 0) {
                list.set(i, next + cur);
                minV = Math.min(minV, 1 + dfs(k + 1, list));
                list.set(i, next);
                if(cur + next == 0) break;
            }
     
            
        }
        return minV;
    }
}