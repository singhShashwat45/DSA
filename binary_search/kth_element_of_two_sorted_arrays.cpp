#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int> &v1, vector<int> &v2, int k) {
        int n = v1.size();
        int m = v2.size();
        if(n > m) return kthElement(v2, v1, k);
        int low = max(0,k-m ), high = min(n, k);
        int left = k;
        int totalSize = n+m;
        while(low <= high){
            int mid1 = low + (high - low)/2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n) r1 = v1[mid1];
            if(mid2 < m) r2 = v2[mid2];
            if(mid1-1 >= 0) l1 = v1[mid1-1];
            if(mid2-1 >= 0) l2 = v2[mid2 -1];
            if(l1<=r2 && l2<= r1){
                return max(l1, l2);
            }
            else if(l1>r2) high = mid1 -1;
            else low = mid1 + 1;
        }
        return 0;
    }
};