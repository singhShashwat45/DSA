#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int mod = 1e9 + 7;
int solve(int i, int n, int amount, vector<int> &book_price, vector<int> &pages, vector<vector<int>> &dp){
    if(i==n) return 0;
    if(dp[i][amount] != -1) return dp[i][amount];
    int buy = 0;
    if(amount >= book_price[i]){
        buy = pages[i] + solve(i+1, n, amount - book_price[i], book_price, pages, dp);
    }
    int notbuy = solve(i+1, n, amount, book_price, pages, dp);
    return dp[i][amount] = max(buy, notbuy);
}

int main() {
    
    int n, amount;
    cin>>n>>amount;
    vector<int> book_price(n);
    vector<int> pages(n);
    vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
    for(int i=0; i<n; i++){
        cin>>book_price[i];
    }
    for(int i=0; i<n; i++){
        cin>>pages[i];
    }
    
    int ans = 0;
    
    for(int i=n-1;i>=0; i--){
        for(int j=1; j<=amount; j++){
            int buy = 0;
            if(j>= book_price[i]){
                buy = pages[i] + dp[i+1][j-book_price[i]];
            }
            int notbuy = dp[i+1][j];
            dp[i][j] = max(buy, notbuy);
        }
    }
    cout<<dp[0][amount];
    
}