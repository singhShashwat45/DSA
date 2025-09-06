#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        int n = edges.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dis(n, 1e9);
        dis[src] = 0;
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, src}); // dist, node
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto &it : adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;
                if(dist + edgeW < dis[adjNode]){
                    dis[adjNode] = dist + edgeW;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }
        return dis;
    }
};