class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid.at(0).size();
        int di[4] = {1, 0, -1, 0};
        int dj[4] = {0, 1, 0, -1};
        int ans=0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                queue<pair<int, int>> q;
                if (grid[i][j] == '1') {
                    ans++;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        int ci = q.front().first;
                        int cj = q.front().second;
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int ni = ci + di[d];
                            int nj = cj + dj[d];
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