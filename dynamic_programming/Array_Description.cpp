#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int mod = 1e9 + 7;

int solve(int i, int prev, int n, int upper, vector<int>&v, vector<vector<int>> &dp){
    if(i==n) return 1;
    if(dp[i][prev] != -1) return dp[i][prev];
    int total = 0;
    if(v[i] != 0){
        if(abs(v[i] - prev) <= 1){
            return solve(i+1, v[i], n, upper, v, dp);
        }
        else {
            return dp[i][prev] = 0;
        }
    }
    for(int j = max(prev-1, 1); j<= min(upper, prev+1); j++){
        total = (total + solve(i+1, j, n, upper, v, dp))%mod;
    }
    return dp[i][prev] = total;
    
}

int main() {
    
    int n, maxi;
    cin>>n>>maxi;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<vector<int>> dp(n, vector<int>(maxi+1, -1));
    int ans = 0;
    if (v[0] != 0) {
        ans = solve(1, v[0], n, maxi, v, dp);
    } else {
        for (int val = 1; val <= maxi; val++) {
            ans = (ans + solve(1, val, n, maxi, v, dp)) % mod;
        }
    }
    cout << ans << "\n";
    
}