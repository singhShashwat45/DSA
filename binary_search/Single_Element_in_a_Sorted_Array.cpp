#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int ans = 0;
        int low = 0;
        int high = n-1;
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        if(nums[0] != nums[1]) return nums[0];

        while(low<= high){
            int mid = low + (high - low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!= nums[mid+1]){
                ans = nums[mid];
                break;
            }
            else if((mid%2 == 1 && nums[mid] == nums[mid-1])|| (mid%2 == 0 && nums[mid] == nums[mid+1])){
                low = mid+1;
            }
            else if((mid%2 == 0 && nums[mid] == nums[mid-1])|| (mid%2 == 1 && nums[mid] == nums[mid+1])){
                high = mid-1;
            }
            
        }
        return ans;

    }
};