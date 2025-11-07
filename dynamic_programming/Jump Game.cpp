#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool solve(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind >= nums.size() - 1) return true;
        if (dp[ind] != -1) return dp[ind];

        for (int jump = 1; jump <= nums[ind]; jump++) {
            if (solve(ind + jump, nums, dp)) {
                return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};
