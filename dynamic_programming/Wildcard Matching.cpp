#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Solution {
public:

    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i==s.size() && j == p.size()){
            return true;
        }
        if(i>s.size() || j>p.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(p[j] == '*'){
            return dp[i][j] = solve(i, j+1, s, p, dp) || solve(i+1, j, s, p, dp);
        }
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(i+1, j+1, s, p, dp);
        }
        
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return solve(0, 0, s, p, dp);
    }
};