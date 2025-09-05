#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans, vis(adj.size(), 0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            vis[node] = 1;
            ans.push_back(node);
            for(auto it: adj[node]){
                if(vis[it]!= 1){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};