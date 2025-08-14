#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int mod = 1e9 + 7;

int solve(int i, int j, int n, vector<vector<char>>&v, vector<vector<int>> &dp){
    if(i==n || j==n || v[n-1][n-1] == '*') return 0;
    if(i==n-1 && j == n-1) return 1;
    if(v[i][j] == '*') return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int right = 0, down=0;
    if(v[i][j] = '.'){
        right =solve(i, j+1, n, v, dp);
        down = solve(i+1, j, n, v, dp);
    }
    return dp[i][j] = (right + down)%mod;
}

int main() {
    
    int n;
    cin>>n;
    vector<vector<char>> v(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    }
    int ans = solve(0, 0, n, v, dp);
    cout<<ans;
    return 0;
}