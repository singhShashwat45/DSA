#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Solution {
  public:
    int countStudents(vector<int> &arr, int pages){
        long long totalPages = 0;
        int student = 1;
        for(int i=0; i<arr.size(); i++){
            if(totalPages + arr[i] <= pages){
                totalPages += arr[i];
            }
            else{
                student += 1;
                totalPages = arr[i];
            }
        }
        return student;
    }
    int findPages(vector<int> &arr, int k) {
        int n= arr.size();
        if(n<k) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = 0;
        for(int i=0; i<n; i++) high += arr[i];
        while(low <= high){
            int mid = low + (high - low)/2;
            if(countStudents(arr, mid) <= k){
                high = mid-1;
            }
            else low = mid+1;
            
        }
        return low;
    }
};