class Solution {
private:
    int m, n;
    void dfs(int r, int c, vector<vector<bool>>& reachable, const vector<vector<int>>& heights) {
        reachable[r][c] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !reachable[nr][nc]) {
                if (heights[nr][nc] >= heights[r][c]) {
                    dfs(nr, nc, reachable, heights);
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<bool>> pac_reachable(m, vector<bool>(n, false));
        vector<vector<bool>> atl_reachable(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            dfs(i, 0, pac_reachable, heights);
            dfs(i, n - 1, atl_reachable, heights);
        }
        
        for (int j = 0; j < n; ++j) {
            dfs(0, j, pac_reachable, heights);
            dfs(m - 1, j, atl_reachable, heights);
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pac_reachable[i][j] && atl_reachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};