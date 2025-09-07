#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        int n = V, sum = 0;
        vector<vector<pair<int, int>>> adj(n);
        vector<int> vis(n, 0);
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); //dist, node
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            if(vis[node] == 1)continue;
            vis[node] = 1;
            sum += dist;
            
            for(auto &it : adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;
                if(!vis[adjNode]){
                    pq.push({edgeW, adjNode});
                }
            }
        }
        return sum;
    }
};