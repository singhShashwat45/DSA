#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!= -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = solve(i-1, j-1, s1, s2, dp);
        }
        return dp[i][j] = 1+ min({solve(i, j-1, s1, s2, dp), solve(i-1, j, s1, s2, dp), solve(i-1, j-1, s1, s2, dp)});
    }

    int minDistance(string s1, string s2) {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return solve(s1.size()-1, s2.size()-1, s1, s2, dp);
    }
};