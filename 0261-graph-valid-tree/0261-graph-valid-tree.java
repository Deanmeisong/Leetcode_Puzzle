class Solution {
    public boolean validTree(int n, int[][] edges) {
//         int[] nums = new int[n];
//         Arrays.fill(nums, -1);
        
//         for(int[] e : edges) {
//             int x = find(nums, e[0]);
//             int y = find(nums, e[1]);
            
//             if(x == y) return false;
            
//             x = nums[y];
//         }
        
//         return n - 1 == edges.length;
//     }
    
//     int find(int[] nums, int i) {
//         if(nums[i] == -1) return i;
//         return find(nums, nums[i]);
                // initialize n isolated islands
        int[] nums = new int[n];
        Arrays.fill(nums, -1);
        
        // perform union find
        for (int[] e : edges) {
            int x = find(nums, e[0]);
            int y = find(nums, e[1]);
            
            // if two vertices happen to be in the same set
            // then there's a cycle
            if (x == y) return false;
            
            // union
            nums[y] = x;
        }
        
        return edges.length == n - 1;
    }
    
    int find(int nums[], int i) {
        if (nums[i] == -1) return i;
        return find(nums, nums[i]);
    }
    
}