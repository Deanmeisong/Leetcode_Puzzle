class Solution {
    public boolean validTree(int n, int[][] edges) {
        int[] nums = new int[n];
        Arrays.fill(nums, -1);
        for(int[] e : edges) {
            int x = find(nums, e[0]);
            int y = find(nums, e[1]);
            if(x == y) return false;
            nums[x] = y;
        }
        return edges.length == n - 1;
    }
    
    int find(int[] nums, int i) {
        if(nums[i] == -1) return i;
        return find(nums, nums[i]);
    } 
}