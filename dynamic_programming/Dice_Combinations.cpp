#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int mod = 1e9 + 7;

int solve(int sum, vector<int> &dp){
    if(sum == 0) return 1;
    if(dp[sum] != -1) return dp[sum];
    int ans = 0;
    for(int i=1; i<=6; i++){
        if(sum-i>=0){
            ans = (ans + solve(sum - i, dp))%mod;
        }
    }
    return dp[sum]= ans%mod;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    int ans = solve(n, dp);
    cout<<ans<<endl;

}