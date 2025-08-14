#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
#define INT_MIN (-2147483647 - 1)

int maxDigit(int n){
    int ans = INT_MIN;
    while(n>0){
        ans = max(ans, n%10);
        n = n/10;
    }
    return ans;
}

int solve(int n, vector<int> &dp){
    if(n ==0) return 0;
    if(dp[n] != -1) return dp[n];
    int ways = 0;
    ways  = 1+ solve(n - maxDigit(n), dp);
    return dp[n] = ways;
}

int main() {
    
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    int ans = solve(n, dp);
    cout<<ans;
    return 0;
}