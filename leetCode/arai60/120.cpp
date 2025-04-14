class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int area = 0;
                // cout << i << " " << j << endl;
                if (grid[i][j] == 1 && !vis[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    while (!q.empty()) {
                        area++;
                        auto [nowx, nowy] = q.front();
                        vis[nowx][nowy] = true;
                        q.pop();
                        for (int num = 0; num < 4; num++) {
                            int nextx = nowx + dx[num];
                            int nexty = nowy + dy[num];
                            if (0 <= nextx && nextx < m && 0 <= nexty &&
                                nexty < n && grid[nextx][nexty] == 1 &&
                                !vis[nextx][nexty]) {
                                q.push({nextx, nexty});
                                vis[nextx][nexty] = true;
                            }
                        }
                    }
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};