class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        const int dx[] = {1, 0, -1, 0};
        const int dy[] = {0, 1, 0, -1};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    stack<pair<int, int>> st;
                    st.push({i, j});
                    while (!st.empty()) {
                        const int nowx = st.top().first;
                        const int nowy = st.top().second;
                        vis[nowx][nowy] = true;
                        st.pop();
                        for (int num = 0; num < 4; num++) {
                            int nextx = nowx + dx[num];
                            int nexty = nowy + dy[num];

                            if (0 <= nextx && nextx < m && 0 <= nexty &&
                                nexty < n && !vis[nextx][nexty]&&grid[nextx][nexty]=='1') {
                                st.push({nextx, nexty});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};