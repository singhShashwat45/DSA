#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int solve(int a, int b, vector<vector<int>> &dp){
    if (a == b) return 0;
    if (dp[a][b] != -1) return dp[a][b];

    int ans = 1e8;
    for (int i = 1; i < a; i++) {
        ans = min(ans, 1 + solve(i, b, dp) + solve(a - i, b, dp));
    }
    for (int j = 1; j < b; j++) {
        ans = min(ans, 1 + solve(a, j, dp) + solve(a, b - j, dp));
    }

    return dp[a][b] = ans;
}

int main()
{
    int a, b;
    cin>> a>>b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
                }
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
                }
            }
        }
    }

    cout << dp[a][b] << "\n";
    return 0;
}