#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for(int i=1; i<nums.size(); i++){
        int take = nums[i];
        if(i>1) take += dp[i-2];
        int notake = dp[i-1];
        dp[i] = max(take, notake);
    }
    return dp[nums.size()-1];
}