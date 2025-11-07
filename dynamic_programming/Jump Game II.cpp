#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:

    int solve(int ind, vector<int>&nums, vector<int> &dp){
        if(ind>=nums.size()-1){
            return 0;
        }
        if(dp[ind]!= -1) return dp[ind];
        int steps = 1e9;
        for(int i=1; i<=nums[ind] ;i++){
            if(i + ind < nums.size()){
                steps = min(steps, 1+ solve(i+ind, nums, dp));
            }
        }
        return dp[ind] = steps;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};