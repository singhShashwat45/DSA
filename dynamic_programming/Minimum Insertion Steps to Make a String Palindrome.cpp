#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Solution {
public:

    int solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i==s.size() || j == p.size()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j]){
            return dp[i][j] = 1 + solve(i+1, j+1, s, p, dp);
        }
        return dp[i][j] = max(solve(i+1, j, s, p, dp), solve(i, j+1, s, p, dp));
    }

    int minInsertions(string s) {
        string p = s;
        reverse(p.begin(), p.end());
        vector<vector<int>> dp(s.size() +1, vector<int>(s.size(), -1));
        return s.size() - solve(0, 0, s, p, dp);
    }
};