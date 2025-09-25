#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;    

int n;
vector<string> grid;
vector<vector<string>> memo;

string dfs(int i, int j) {
    if (i == n-1 && j == n-1) {
        return string(1, grid[i][j]);
    }
    if (!memo[i][j].empty()) return memo[i][j];

    string best = "{"; // '{' is after 'Z' in ASCII, acts like infinity

    if (i+1 < n) {
        best = min(best, dfs(i+1, j));
    }
    if (j+1 < n) {
        best = min(best, dfs(i, j+1));
    }

    // prepend current character
    return memo[i][j] = grid[i][j] + best;
}

int main() {
    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    memo.assign(n, vector<string>(n, ""));
    cout << dfs(0, 0);

    return 0;
}
