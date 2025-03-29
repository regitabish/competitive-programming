class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++; // Found a new island
                    stack<pair<int, int>> st;
                    st.push({i, j});
                    while (!st.empty()) {
                        int nowi = st.top().first;
                        int nowj = st.top().second;
                        st.pop();
                        vis[nowi][nowj] = true;

                        // Check the four possible directions
                        for (int num = 0; num < 4; num++) {
                            int ni = nowi + dx[num];
                            int nj = nowj + dy[num];

                            // Boundary check and unvisited land check
                            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1' && !vis[ni][nj]) {
                                st.push({ni, nj});
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};