//Dijkstra fails on  negative cycles and negative edges
//Applied only on directed graph(we can make directed graph from undirected graph(->, <-))
//Can be applied if graph has -ve edges and cycles


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dis(V, 1e8);
        dis[src] = 0;
        for(int i=0; i<V-1; i++){
            for(auto &it : edges){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                if(dis[u] != 1e8 && dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                }
                
            }
        }
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dis[u] != 1e8 && dis[u] + w < dis[v]){
                return {-1};
            }
            
        }
        return dis;
    }
};
