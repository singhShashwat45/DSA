#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    pair<int,int> solve(int i, int prev, vector<int>& nums, vector<vector<pair<int,int>>>& dp) {
        if (i == nums.size()) return {0, 1}; // base: one empty subsequence

        if (dp[i][prev + 1].first != -1) return dp[i][prev + 1];

        int maxLen = 0;
        int count = 0;

        // Option 1: skip current element
        auto skip = solve(i + 1, prev, nums, dp);
        maxLen = skip.first;
        count = skip.second;

        // Option 2: take current element if valid
        if (prev == -1 || nums[i] > nums[prev]) {
            auto take = solve(i + 1, i, nums, dp);
            int newLen = 1 + take.first;

            if (newLen > maxLen) {
                maxLen = newLen;
                count = take.second;
            } 
            else if (newLen == maxLen) {
                count += take.second;
            }
        }

        return dp[i][prev + 1] = {maxLen, count};
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n + 1, {-1, 0}));

        auto res = solve(0, -1, nums, dp);
        return res.second;
    }
};
