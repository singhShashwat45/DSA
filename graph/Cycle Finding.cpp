#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    vector<long long> dist(n + 1, 0), parent(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    int x = -1;

    // Relax edges n times
    for (int i = 1; i <= n; i++) {
        x = -1;
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if ( dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v; // track last relaxed vertex
            }
        }
    }

    if (x == -1) {
        cout << "NO\n"; // no negative cycle
    } else {
        cout << "YES\n";
        // ensure we are inside the cycle
        for (int i = 0; i < n; i++) {
            x = parent[x];
        }

        vector<int> cycle;
        int cur = x;
        do {
            cycle.push_back(cur);
            cur = parent[cur];
        } while (cur != x && cur != -1);
        cycle.push_back(x);

        reverse(cycle.begin(), cycle.end());

        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
