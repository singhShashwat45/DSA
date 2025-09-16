#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
int main(){
    int n, m; cin>>n>>m;
    vector<vector<pair<int, int>>> adj(n+1);
    const long long INF = 1e18;
    vector<vector<long long>> dist(n+1, vector<long long>(2, INF));
    vector<long long> maxEdge(n + 1, 0);
    dist[1][0] = 0;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
    }
 
    // tuple = {distance, node, usedCoupon}
    priority_queue<
        tuple<long long,int,int>,
        vector<tuple<long long,int,int>>,
        greater<>
    > pq;

    pq.push({0, 1, 0});
    while (!pq.empty()) {
        auto [d, u, used] = pq.top();
        pq.pop();
        if (d > dist[u][used]) continue;

        for (auto [v, w] : adj[u]) {
            // normal edge
            if (d + w < dist[v][used]) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }
            // discounted edge if coupon unused
            if (!used && d + w/2 < dist[v][1]) {
                dist[v][1] = d + w/2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout << dist[n][1]; 
}