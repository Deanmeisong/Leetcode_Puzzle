class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int m = image.size(), n = image[0].size();
        dfs(image, sr, sc, m, n, color, image[sr][sc]);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int x, int y, int m, int n, int newColor, int oldColor) {
        if(x < 0 or x >= m or y < 0 or y >= n) return;
        if(image[x][y] != oldColor) return;
        image[x][y] = newColor;
        dfs(image, x + 1, y, m, n, newColor, oldColor);
        dfs(image, x - 1, y, m, n, newColor, oldColor);
        dfs(image, x, y + 1, m, n, newColor, oldColor);
        dfs(image, x, y - 1, m, n, newColor, oldColor);
    }
};