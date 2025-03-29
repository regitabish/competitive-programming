class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        int ans = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    int tmp = 0;
                    
                    while (!q.empty()) {
                        int nowx = q.front().first;
                        int nowy = q.front().second;
                        q.pop();
                        tmp++;
                        
                        for (int d = 0; d < 4; d++) {
                            int nextx = nowx + dx[d];
                            int nexty = nowy + dy[d];
                            if (0 <= nextx && nextx < m && 0 <= nexty && nexty < n &&
                                grid[nextx][nexty] == 1 && !vis[nextx][nexty]) {
                                q.push({nextx, nexty});
                                vis[nextx][nexty] = true; // ここで訪問済みにする
                            }
                        }
                    }
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};
