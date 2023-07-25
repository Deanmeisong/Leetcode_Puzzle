class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        dfs(image, sr, sc, image.length, image[0].length, image[sr][sc], color);
        return image;
    }
    
    void dfs(int[][] image, int x, int y, int m, int n, int oc, int nc) {
        if(x < 0 || x >= m || y < 0 || y >= n || image[x][y] != oc) return;
        image[x][y] = nc;
        dfs(image, x + 1, y, m, n, oc, nc);
        dfs(image, x - 1, y, m, n, oc, nc);
        dfs(image, x, y + 1, m, n, oc, nc);
        dfs(image, x, y - 1, m, n, oc, nc);
    }
}