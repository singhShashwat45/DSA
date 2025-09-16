#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool good(int mid, vector<int> &v, int d) {
        int dayNeed = 1, cur = 0;
        for(auto w: v){
            if(cur + w > mid){
                dayNeed++;
                cur = 0;
            }
            cur += w;
        }
        return dayNeed <= d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (good(mid, weights, days)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};