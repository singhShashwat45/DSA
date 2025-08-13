#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Solution {
  public:

    int solve(int n, int k, vector<vector<int>> &dp){
        if(k == 1 || k==0) return k;
        
        if(n == 1) return k;
        if (dp[n][k] != -1) return dp[n][k];
        int mini = 1e9;
        for(int i = 1; i<= k; i++){
            int ans = 1 + max(solve(n-1, i-1, dp), solve(n, k-i, dp)); // break , non-break
            mini = min(mini, ans);
        }
        return dp[n][k] = mini;
    }
    
    int eggDrop(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(n, k, dp);
        
        
        
    }
};