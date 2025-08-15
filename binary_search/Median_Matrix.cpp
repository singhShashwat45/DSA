#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Solution {
  public:
  
    int upperbound(vector<int> &v, int mid){
        int n = v.size();
        int low = 0; int high = n-1;
        int ans = n;
        while(low<= high){
            int midd = low + (high-low)/2;
            if(v[midd] > mid){
                ans = midd;
                high = midd-1;
            }
            else low = midd+1;
        }
        return ans;
    }
  
    int solve(vector<vector<int>> &mat, int mid){
        int n = mat.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            cnt += upperbound(mat[i], mid);
        }
        return cnt;
    }
    
    int median(vector<vector<int>> &mat) {
        int low = INT_MAX, high = INT_MIN;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++){
            low = min(low, mat[i][0]);
        }
        for(int i=0; i<n; i++){
            high = max(high, mat[i][m-1]);
        }
        int req = (n*m)/2;
        while(low <= high){
            int mid = low + (high-low)/2;
            int no_of_ele_less_than_req = solve(mat, mid);
            if(no_of_ele_less_than_req <= req){
                low = mid+1;
            }
            else high = mid-1;
            
        }
        
        return low;
    }
};
