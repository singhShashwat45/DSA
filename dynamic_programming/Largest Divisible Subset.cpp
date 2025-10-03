#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Solution {
public:

    int solve(int i, vector<int>& nums, int prev, vector<vector<int>> &dp) {
        if (i == nums.size()) return 0;
        if (dp[i][prev] != -1) return dp[i][prev];
        int notTake = solve(i + 1, nums, prev, dp);

        int take = 0;
        if (prev == 0 || nums[i] % nums[prev - 1] == 0) {
            take = 1 + solve(i + 1, nums, i + 1, dp);
        }

        return dp[i][prev] = max(take, notTake);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int len = solve(0, nums, 0, dp);
        int i = 0, prev = 0;
        vector<int> ans;
        while(i<n && len>0){
            if((prev == 0 || nums[i] % nums[prev-1] == 0) && dp[i][prev] == 1+solve(i + 1, nums, i + 1, dp)){
                ans.push_back(nums[i]);
                prev = i+1;
                len--;
            }
            i++;
        }
        return ans;
    }
};