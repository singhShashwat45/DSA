#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    int solve(int left, int right, vector<int>& nums, vector<vector<int>> &dp){
        if (left > right) return 0;
        if(dp[left][right]!= -1 ) return dp[left][right];
        int ans = INT_MIN;
        for(int i=left; i<=right; i++){
            int cost = nums[left-1]*nums[i]*nums[right+1] + solve(left, i-1, nums, dp) + solve(i+1, right, nums, dp);
            ans = max(ans, cost);
        }
        return dp[left][right] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return solve(1, n, nums, dp);
    }
};