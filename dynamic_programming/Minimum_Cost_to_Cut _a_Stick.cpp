#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:

    int solve(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
        if(i > j) return 0;
        int mini = 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        for(int ind = i; ind <= j; ind++){
            int cost = cuts[j+1] - cuts[i-1] + solve(i, ind-1, cuts, dp) + solve(ind+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(1, cuts.size() - 2, cuts, dp);
    }
};