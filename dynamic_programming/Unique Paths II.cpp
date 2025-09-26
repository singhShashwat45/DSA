#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n) return 0;
        if (grid[i][j] == 1) return 0;
        if (i == m-1 && j == n-1) return 1;

        if (dp[i][j] != -1) return dp[i][j];  
        int down  = solve(i+1, j, grid, dp);
        int right = solve(i, j+1, grid, dp);

        return dp[i][j] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, grid, dp);
    }
};
