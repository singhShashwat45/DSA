#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int mod = 1e9 + 7;

int solve(int i, int n, int sum, vector<int>&v, vector<vector<int>> &dp){
    if(i == n) return 1e9;
    if(sum == 0) return 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    int take = 1e9;
    if(v[i] <= sum){
        take = 1 + solve(i, n, sum-v[i], v, dp);
    }
    int notake = solve(i+1, n, sum, v, dp);
    return dp[i][sum] = min(take, notake);
}

int main(){
    int n, sum;
    cin>>n>>sum;
    vector<int> v(n);
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 1e9));
    for(int i=0; i<n; i++) cin>>v[i];
    for (int j = 0; j <= n; j++) dp[j][0] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= sum; j++) {
            int take = 1e9;
            if(v[i]<=j){
                take = 1+dp[i][j-v[i]];
            }
            int notake = dp[i+1][j];
            dp[i][j] = min(take, notake);
        }
    }
    if(dp[0][sum] >= 1e9) cout<<-1<<endl;
    else
    cout<<dp[0][sum];


}