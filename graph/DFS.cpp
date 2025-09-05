#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    void solve(int node, vector<vector<int>>& adj, vector<int> &vis, vector<int> & ans){
        vis[node] = 1;
        ans.push_back(node);
        for(auto &it : adj[node]){
            if(vis[it] != 1){
                solve(it, adj , vis, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans, vis(n, 0);
        solve(0, adj, vis, ans);
        return ans;
    }
};