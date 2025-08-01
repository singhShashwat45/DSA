#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        int fact = 1;
        string ans="";
        for(int i=1; i<n; i++){
            fact = fact*i;
            num.push_back(i);
        }
        num.push_back(n);
        k=k-1;
        while(true){
            int idx = k / fact;
            ans += to_string(num[idx]);
            num.erase(num.begin() +idx);
            if (num.empty()) break;
            k=k%fact;
            fact = fact/num.size();
        }
        return ans;
    }
};