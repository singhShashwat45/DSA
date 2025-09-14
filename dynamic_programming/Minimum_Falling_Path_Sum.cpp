#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
//Memoization
    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        int n = mat.size();
        if(j < 0 || j >= n) return 1e9;
        if(i==n-1) return mat[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int bel = mat[i][j] + solve(i+1, j, mat, dp);
        int diaLeft = mat[i][j] + solve(i+1, j-1, mat, dp);
        int diaRight = mat[i][j] + solve(i+1, j+1, mat, dp);
        return dp[i][j] = min(bel, min(diaLeft, diaRight));
    }
//Tabulation
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int j = 0; j < n; j++) {
            dp[0][j] = mat[0][j];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int up = dp[i-1][j];
                int leftDiag = (j > 0) ? dp[i-1][j-1] : 1e9;
                int rightDiag = (j < n-1) ? dp[i-1][j+1] : 1e9;

                dp[i][j] = mat[i][j] + min({up, leftDiag, rightDiag});
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};