#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    void solve(int ind, vector<int>& candidates, int target, vector<int> &v, vector<vector<int>> &ans, int n){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        for(int i = ind; i<n; i++){
            if(i > ind && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i]<=target){
                v.push_back(candidates[i]);
                solve(i+1, candidates, target-candidates[i], v, ans, n);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        vector<vector<int>> ans;
        int n = candidates.size();
        solve(0, candidates, target, v, ans, n);
        return ans;
    }
};