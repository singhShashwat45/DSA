#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int mod = 1e9 + 7;

int solve(int sum){
    if(sum == 0) return 1;
    int ans = 0;
    for(int i=1; i<=6; i++){
        if(sum-i>=0){
            ans = (ans + solve(sum - i))%mod;
        }
    }
    return ans%mod;
}

int main(){
    int n;
    cin>>n;
    int ans = solve(n);
    cout<<ans<<endl;

}