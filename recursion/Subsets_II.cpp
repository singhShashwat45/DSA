#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

    void func(vector<int>& nums, int ind, vector<vector<int>>&ans, vector<int> &v, int n){
        ans.push_back(v);

        for(int i=ind; i<n;i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            func(nums, i+1, ans,v,n);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int>v;
        func(nums, 0, ans, v, nums.size());
        return ans;
    }
};