#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//Memoiozation
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = grid[i][j] + solve(i-1, j, grid, dp);
        int left = grid[i][j] + solve(i, j-1, grid, dp);
        return dp[i][j] =  min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, grid, dp);
    }
};

//Tabulation

int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++)
            dp[i][0] = grid[i][0] + dp[i-1][0];

        for(int j = 1; j < m; j++)
            dp[0][j] = grid[0][j] + dp[0][j-1];
            
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int up = grid[i][j] + dp[i-1][j];
                int left = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(left, up);
            }
        }
        return dp[n-1][m-1];
    }