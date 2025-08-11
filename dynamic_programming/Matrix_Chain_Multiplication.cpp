#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
  public:
    int solve(int i, int j, vector<int> &arr,vector<vector<int>> &dp){
        if(i==j) return 0;
        int mini = 1e9;
        if(dp[i][j]!= -1) return dp[i][j];
        for(int k=i; k<j;k++){
            int steps = arr[i-1]*arr[k]*arr[j] + solve(i,k, arr, dp) + solve(k+1, j, arr, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
        return solve(1,arr.size()-1, arr, dp);
        
    }
};