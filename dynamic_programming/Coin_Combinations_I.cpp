#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

const int mod = 1e9 + 7;
int solve(int sum, vector<int> &coins, vector<int> &dp){
    if (sum==0) return 1;
    if (sum < 0) return 0;
    if(dp[sum]!=-1) return dp[sum];
    int ans = 0;
    for (int i = 0; i < coins.size(); i++) {
        if (coins[i] <= sum) {
            (ans += solve(sum - coins[i], coins, dp)) %= mod;
        }
    }
    return dp[sum] = ans;
}
int main(){
    int n, sum;
    cin>>n>>sum;
    vector<int> coins(n);
    vector<int> dp(sum + 1, -1);
    for(int i=0; i<n; i++) cin>>coins[i];
    int ans= solve(sum, coins, dp);
    cout<<ans<<"\n";
}
