#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:

    int countSubarrays(vector<int>& nums, int maxSum) {
        int count = 1;
        long long curSum = 0;
        for (int num : nums) {
            if (curSum + num > maxSum) {
                count++;
                curSum = num;
            } else {
                curSum += num;
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(countSubarrays(nums, mid) <= k){
                r = mid - 1;
                ans = mid;
            }
            else l = mid+1;
        }
        return ans;
    }
};