#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int good(int mid, vector<int>& arr) {
        int cnt = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
        return mid - cnt; // total numbers till mid - how many are present
    }

    int findKthPositive(vector<int>& arr, int k) {
        int l = 1;
        int r = arr.back() + k;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(good(mid, arr) >= k){
                ans = mid;
                r = mid - 1;
            }
            else
            l = mid+1;
        }
        return ans;

    }
};