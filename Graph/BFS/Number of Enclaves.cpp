class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,
              int j) {
        bool find = 0;

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        int count = 0;

        while (!q.empty()) {
            int ith = q.front().first;
            int jth = q.front().second;
            q.pop();

            if (ith == 0 || jth == 0 || ith == grid.size() - 1 ||
                jth == grid[0].size() - 1) {
                find = 1;
            }

            int forI[] = {-1, 0, 1, 0};
            int forJ[] = {0, 1, 0, -1};
            count++;
            for (int i = 0; i < 4; i++) {
                int newI = forI[i] + ith;
                int newJ = forJ[i] + jth;

                if (newI >= 0 && newI < grid.size() && newJ >= 0 &&
                    newJ < grid[0].size() && grid[newI][newJ] == 1 &&
                    !visited[newI][newJ]) {
                    visited[newI][newJ] = true;
                    q.push({newI, newJ});
                }
            }
        }

        if (find) {
            return 0;
        }
        return count;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    count += solve(grid, visited, i, j);
                }
            }
        }
        return count;
    }
};