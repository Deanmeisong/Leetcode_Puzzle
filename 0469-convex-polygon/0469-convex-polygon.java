class Solution {
    public boolean isConvex(List<List<Integer>> points) {
        
       int flag = 0;
        
        int size = points.size();
        
        for (int i = 0; i < size; i++) {
            List<Integer> a = points.get(i);
            List<Integer> b = points.get((i + 1) % size);
            List<Integer> c = points.get((i + 2) % size);
            
            int orientation = helper(a.get(0), a.get(1), b.get(0), b.get(1), c.get(0), c.get(1));
            
            if (orientation == 0) {
                continue;
            }
            
            if (flag == 0) {
                flag = orientation;
            } else if (flag != orientation) {
                return false;
            }
        }
        
        return true;
    }

    public int helper(int ax, int ay, int bx, int by, int cx, int cy) {
        int val = (ax - bx) * (cy - by) - (cx - bx) * (ay - by);
        
        if(val == 0) return 0;
        
        return val > 0 ? 1 : -1;
    }
}