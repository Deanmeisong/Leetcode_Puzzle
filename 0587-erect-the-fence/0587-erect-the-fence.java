class Solution {
    public int[][] outerTrees(int[][] points) {
        // List<int[]> res = new ArrayList<>();
        // Arrays.sort(points, new Comparator<int[]>(){
        //     public int compare(int[] p, int[] q) {
        //         return q[0] == p[0] ? q[1] - p[1] : p[0] - q[0]; 
        //     }
        // });
        // Stack<int[]> hull = new Stack<>();
        // for(int i = 0; i < points.length; ++i) {
        //     while(hull.size() >= 2 && orientation(hull.get(hull.size() - 2), hull.peek(), points[i]) > 0)
        //         hull.pop();
        //     hull.push(points[i]);
        // }
        // hull.pop();
        // for(int i = points.length - 1; i >= 0; --i) {
        //     while(hull.size() >= 2 && orientation(hull.get(hull.size() - 2), hull.peek(), points[i]) >0)
        //         hull.pop();
        //     hull.push(points[i]);
        // }
        // res.add(new HashSet<>(hull));
        // return res;
        
        // List<int[]> res = new ArrayList<>();
        int[][] res;
        Arrays.sort(points, new Comparator < int[] > () {
            public int compare(int[] p, int[] q) {
                return q[0] == p[0] ? q[1] - p[1] : p[0] - q[0];
            }
        });
        Stack<int[]> hull = new Stack < > ();
        for (int i = 0; i < points.length; i++) {
            while (hull.size() >= 2 && orientation(hull.get(hull.size() - 2), hull.peek(), points[i]) > 0)
                hull.pop();
            hull.push(points[i]);
        }
        hull.pop();
        for (int i = points.length - 1; i >= 0; i--) {
            while (hull.size() >= 2 && orientation(hull.get(hull.size() - 2), hull.peek(), points[i]) > 0)
                hull.pop();
            hull.push(points[i]);
        }
        // res.addAll(new HashSet<>(hull));
        HashSet<int[]> hullSet = new HashSet<>(hull);

        return hullSet.toArray(new int[hullSet.size()][]);
    }
    
    public int orientation(int[] p, int[] q, int[] r) {
        return (q[1] - p[1]) * (r[0] - p[0]) - (q[0] - p[0]) * (r[1] - p[1]);
    }
    

}