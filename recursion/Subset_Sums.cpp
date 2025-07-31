#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void func(vector<int> arr, int n, vector<int>&ans, int ind, int sum){
        
        if(ind==n){
            ans.push_back(sum);
            return;
        }
        func(arr, n, ans, ind+1,sum+arr[ind]);

        func(arr, n, ans, ind+1, sum);
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        func(arr,n, ans,0,0);
        return ans;
    }
};