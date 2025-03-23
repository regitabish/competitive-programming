class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int di[4] = {1, 0, -1, 0};
        int dj[4] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ans++;
                    grid[i][j] = '0';
                    q.push({i, j});
                    while (!q.empty()) {
                        int ci = q.front().first;
                        int cj = q.front().second;
                        q.pop();
                        for (int num = 0; num < 4; num++) {
                            int ni = ci + di[num];
                            int nj = cj + dj[num];
                            if (0 <= ni && ni < m && 0 <= nj && nj < n &&
                                grid[ni][nj] == '1') {
                                grid[ni][nj] = '0';
                                q.push({ni, nj});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};