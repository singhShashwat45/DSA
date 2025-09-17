#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


vector<int> lcs(int i, int j, vector<int> &v1, vector<int> &v2, vector<vector<vector<int>>> &dp) {
    if (i == v1.size() || j == v2.size()) return {};

    if (!dp[i][j].empty()) return dp[i][j];

    if (v1[i] == v2[j]) {
        vector<int> res = lcs(i + 1, j + 1, v1, v2, dp);
        res.insert(res.begin(), v1[i]);
        return dp[i][j] = res;
    } else {
        vector<int> option1 = lcs(i + 1, j, v1, v2, dp);
        vector<int> option2 = lcs(i, j + 1, v1, v2, dp);

        if (option1.size() > option2.size())
            return dp[i][j] = option1;
        else
            return dp[i][j] = option2;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for (int i = 0; i < n; i++) cin >> v1[i];
    for (int i = 0; i < m; i++) cin >> v2[i];

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1));

    vector<int> result = lcs(0, 0, v1, v2, dp);

    cout<< result.size() << "\n";
    for (int x : result) cout << x << " ";
    cout << "\n";
}
