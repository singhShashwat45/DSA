#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1, 1e9);
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});//time, node
        while(!pq.empty()){
            auto it = pq.top();
            int time = it.first;
            int node = it.second;
            pq.pop();

            for(auto &it: adj[node]){
                int curtime = it.second;
                int adjnode = it.first;
                if(curtime + time < dist[adjnode]){
                    dist[adjnode] = curtime + time;
                    pq.push({dist[adjnode], adjnode});
                }
            }

        }
        int ans = 0;
        for(int i=1; i<n+1; i++){
            if(dist[i] == 1e9)
            return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};