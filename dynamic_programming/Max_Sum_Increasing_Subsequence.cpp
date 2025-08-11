#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
  public:
    
    int solve(int cur, int prev, vector<int>& arr, vector<vector<int>> &dp){
        if(cur == arr.size()){
            return 0;
        }
        if(dp[cur][prev+1] != -1){
            return dp[cur][prev+1];
        }
        int take = 0;
        if(prev == -1 || arr[cur] > arr[prev]){
            take = arr[cur] + solve(cur+1, cur, arr, dp);
        }
        int notake = solve(cur+1, prev, arr, dp);
        
        return dp[cur][prev+1]=max(take, notake);
    }
    
    int maxSumIS(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size()+1, -1));
        return solve(0, -1, arr, dp);
    }
    
};