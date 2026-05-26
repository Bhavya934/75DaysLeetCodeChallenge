class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int initialColor, int newColor) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != initialColor) {
            return;
        }
        
        image[r][c] = newColor;
        
        dfs(image, r + 1, c, initialColor, newColor);
        dfs(image, r - 1, c, initialColor, newColor);
        dfs(image, r, c + 1, initialColor, newColor);
        dfs(image, r, c - 1, initialColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if (initialColor != color) {
            dfs(image, sr, sc, initialColor, color);
        }
        return image;
    }
};