#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(int i, vector<int>& candidates, int target, int n, vector<vector<int>>& ans, vector<int>& ds){
        if(i == n){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(target >= candidates[i]){
            ds.push_back(candidates[i]);
            solve(i, candidates, target-candidates[i], n, ans, ds);
            ds.pop_back();
        }
        
        solve(i+1, candidates, target, n, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0, candidates, target, n, ans, ds);
        return ans;
    }
};