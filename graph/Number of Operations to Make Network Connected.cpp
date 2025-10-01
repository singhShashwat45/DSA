#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int> & vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& con) {
        int sz = con.size();
        if(sz < n-1) return -1;
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for(auto &it: con){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                ans ++;
                dfs(i, adj, vis);
            }
        }
        return ans -1;
    }
};