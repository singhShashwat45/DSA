#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        if(i<0 || j< 0){
            return 0;
        }
        if(dp[i][j]!= -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] =  1+ solve(i-1, j-1, s1, s2, dp);
        }
        return dp[i][j] =  max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1,s2, dp));
    }

    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        // return solve(s1.size()-1, s2.size()-1, s1, s2, dp);
        for(int i=0; i<s1.size(); i++){
            for(int j=0; j<s2.size(); j++){
                if(s1[i] == s2[j]){
                    dp[i+1][j+1] = 1+ dp[i][j];
                }else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
                
            }
        }
        return dp[s1.size()][s2.size()];
    }
};